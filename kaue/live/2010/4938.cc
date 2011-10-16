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

char to_char(int j) {
  char res = j + 'a';
  if (res > 'z') res = ' ';
  return res;
}

char next(char c) {
  if (c == 'Z') c = ' ';
  else if (c == ' ') c = 'A';
  else c++;
  return c;
}
 
int main() {
  string code, number;
  getline(cin, code, ':');
  cin >> number;
  //ppn(code);
  //ppn(number);
  int n = s(code);
  int val[15][300] = {{0}};
  ri {
    char cur = code[i];
    r(j, 'z' - 'a' + 2) {
      val[i][cur] = to_char(j);
      cur = next(cur);
    }
  }
  string s;
  getline(cin, s);
  while (getline(cin, s)) {
    //ppn(s);
    int cur = 0;
    int cnt = 0;
    string out = s;
    r(i, s(s)) {
      //ppn(cur);
      //ppn(number[cur]);
      out[i] = val[cur][s[i]];
      cnt++;
      if (cnt == number[cur] - '0') {
        cur++;
        cur %= n;
        cnt = 0;
      }
    }
    cout << out << endl;
  }
} 

