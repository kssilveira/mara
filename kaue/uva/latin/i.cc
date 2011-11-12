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

char what[10][3][3] = {
  // 0 here
  {".*", "**", ".."},
  {"*.", "..", ".."}, 
  {"*.", "*.", ".."},
  {"**", "..", ".."},
  {"**", ".*", ".."},
  {"*.", ".*", ".."},
  {"**", "*.", ".."},
  {"**", "**", ".."},
  {"*.", "**", ".."},
  {".*", "*.", ".."}
};

 
int main() {
  int d;
  while (cin >> d && d > 0) {
    //ppn(d);
    char c;
    cin >> c;
    //ppn(c);
    if (c == 'S') {
      string s;
      cin >> s;
      string res[3];
      //ppn(d);
      r(line, 3) {
        r(i, d) {
          int num = s[i] - '0';
          //ppn(num);
          if (i) { res[line] += ' '; }
          res[line] += what[num][line];
        }
        cout << res[line] << endl;
      }
    } else {
      string s[3];
      getline(cin, s[0]);
      r(line, 3) {
        //cin >> s[line];
        getline(cin, s[line]);
        //ppn(s[line]);
      }
      string res;
      r(i, d) {
        int by = i * 3;
        r(num, 10) {
          bool wrong = false;
          r(x, 3) {
            r(y, 2) {
              if (s[x][y + by] != what[num][x][y]) {
                wrong = true;
                break;
              }
            }
            if (wrong) break;
          }
          if (!wrong) {
            res += (num + '0');
            break;
          }
        }
      }
      cout << res << endl;
    }
  }
  //ppn(d);
} 

