#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)

#define p(x) cout << x << " "
#define pl cout << endl
#define pn(x) cout << x << endl
#define pv(v) ri { p(v[i]); } pl;
#define pm(m) ri { rjm { p(m[i][j]); } pl; } pl;
#define pp(x) " "#x" " << x
#define ppn(x) pn(pp(x))
#define ppp(x) p(pp(x))

#define in(x) cin >> x
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

string s;

string state = "SLLLLLLMRRRRRRE";
string spat = "101";
string mpat = "01010";
string dpat[2][10] = {
//char dpat[2][10][10] = {
  {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"},
  {"1110010", "1100110", "1101100", "1000010", "1011100", "1001110", "1010000", "1000100", "1001000", "1110100"}};
vector<string> res;

bool match(int ind, string what) {
  r(i, s(what)) {
    if (s[ind + i] != '?' &&
        s[ind + i] != what[i])
      return false;
  }
  //printf("matched(%d, %s)\n", ind, what.c_str());
  /*
  r(i, s(what)) {
    cout << s[ind + i];
  }
  cout << endl;//*/
  return true;
}

bool check(const string& curs) {
  vi val(s(curs));
  r(i, s(curs)) {
    val[i] = curs[i] - '0';
  }
  int sum = 0;
  for (int i = 0; i < s(curs); i += 2) {
    sum += val[i];
  }
  sum *= 3;
  for (int i = 1; i < s(curs) - 1; i += 2) {
    sum += val[i];
  }
  sum %= 10;
  /*
  r(i, s(curs)) {
    cout << val[i] << ' ';
  }
  cout << endl;//*/
  if (sum != 0) sum = 10 - sum;
  //ppn(sum);
  return sum == val[11];
}

bool solve(int stateind, int ind, string curs) {
  //printf("solve(%d, %d, %s)\n", stateind, ind, curs.c_str());
  if (stateind == s(state)) {
    if (check(curs)) {
      res.push_back(curs);
    }
    return s(res) == 9;
  }
  if (s(res) == 9) {
    return true;
  }
  int c = state[stateind];
  if (c == 'S' || c == 'E') {
    if (match(ind, spat)) {
      if (solve(stateind + 1, ind + s(spat), curs)) {
        return true;
      }
    }
  } else if (c == 'L' || c == 'R') {
    r(i, 10) {
      if (match(ind, dpat[c == 'R'][i])) {
        if(solve(stateind + 1, ind + 7, curs + ((char)('0' + i)))) {
          return true;
        }
      }
    }
  } else if (c == 'M') {
    if (match(ind, mpat)) {
      if (solve(stateind + 1, ind + s(mpat), curs)) {
        return true;
      }
    }
  }
  return false;
}
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    int t;
    cin >> t;
    string s1;
    cin >> s >> s1;
    s += s1;
    //ppn(s);

    res.clear();
    string temp;
    solve(0, 0, temp);
    vector<string> other = res;

    res.clear();
    temp = "";
    reverse(all(s));
    solve(0, 0, temp);

    r(i, s(other)) {
      res.push_back(other[i]);
    }
    sort(all(res));
    int cnt = s(res);
    if (cnt > 9) cnt = 9;
    if (s(res) > 8) res.resize(8);
    cout << t << ' ' << cnt << endl;
    r(i, s(res)) {
      cout << res[i] << endl;
    }
  }
} 

