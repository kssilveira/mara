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

char note[][5] = {
  "  |\\",
  "  | ",
  "#x| "};

char out[11][110];
 
int main() {
  // p(strlen("|------------------------|------------------------|--------------|\\----|\\--|------------------------"));
  r(i, 11) {
    r(j, 101) {
      if (!(j % 25)) out[i][j] = '|';
      else if (!(i % 2)) out[i][j] = ' ';
      else out[i][j] = '-';
    }
  }
  int n;
  while (scanf("%d", &n) && n != -1) {
    int col = 1;
    ri {
      char s[5];
      scanf("%s", s);
      int ind = (s[0] - 'A' + 3) % 7;
      ind = 7 - ind;
      // ppn(ind);
      r(ii, 3) {
        r(j, 4) {
          int ni = ind + ii, nj = col + j;
          if (note[ii][j] == '#') {
            if (s[1] == '#') {
              out[ni][nj] = '#';
            }
          } else if(note[ii][j] != ' ') {
            out[ni][nj] = note[ii][j];
          }
        }
      }
      if (i % 4 == 3) {
        col++;
      }
      col += 6;
      if (i % 16 == 15 || i == n - 1) {
        r(ii, 11) {
          if (i <= 15) cout << "|";
          else cout << " ";
          r(j, 101) {
            cout << out[ii][j];
          }
          if (i == n - 1) cout << "|";
          else cout << " ";
          cout << endl;
        }
        // pl;
        r(i, 11) {
          r(j, 101) {
            if (!(j % 25)) out[i][j] = '|';
            else if (!(i % 2)) out[i][j] = ' ';
            else out[i][j] = '-';
          }
        }
        col = 1;
      }
    }
    cout << endl;
  }
} 

