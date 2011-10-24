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

vector<string> words;
vector<string> v[20];
char go[80][256],
     back[80][256];

bool solve(int cur) {
  //printf("solve(%d)\n", cur);
  /*
  for (int i = 'a'; i <= 'z'; i++) {
    if (go[cur][i]) {
      cout << (char)i << " => " << go[cur][i] << endl;
    }
  }//*/
  if (cur == s(words)) {
    return true;
  }
  const string& word = words[cur];
  int n = s(word);
  r(i, s(v[n])) {
    memcpy(go[cur + 1], go[cur], sizeof(go[cur]));
    memcpy(back[cur + 1], back[cur], sizeof(back[cur]));
    bool invalid = false;
    r(j, n) {
      if (!go[cur + 1][word[j]] && !back[cur + 1][v[n][i][j]]) {
        go[cur + 1][word[j]] = v[n][i][j];
        back[cur + 1][v[n][i][j]] = word[j];
      } else if (go[cur + 1][word[j]] != v[n][i][j] ||
          back[cur + 1][v[n][i][j]] != word[j]) {
        invalid = true;
        break;
      }
    }
    if (invalid) continue;
    if (solve(cur + 1)) {
      return true;
    }
  }
  return false;
}
 
int main() {
  int n;
  cin >> n;
  ri {
    string s;
    cin >> s;
    v[s.size()].push_back(s);
  }
  string line;
  getline(cin, line);
  while (getline(cin, line)) {
    words.clear();
    memset(go, 0, sizeof(go));
    memset(back, 0, sizeof(back));
    //cout << "WTF?" << endl;
    //ppn(line);
    istringstream input(line);
    string word;
    while (input >> word) {
      //ppn(word);
      words.push_back(word);
    }
    bool res = solve(0);
    if (res) {
      r(i, s(words)) {
        //ppn(i);
        //ppn(words[i]);
        if (i) cout << ' ';
        r(j, s(words[i])) {
          //ppn(words[i][j]);
          cout << go[s(words)][words[i][j]];
        }
      }
      cout << endl;
    } else {
      r(i, s(words)) {
        if (i) cout << ' ';
        r(j, s(words[i])) {
          cout << '*';
        }
      }
      cout << endl;
    }
  }
} 

