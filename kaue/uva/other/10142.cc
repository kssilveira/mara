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
 
int main() {
  int T;
  cin >> T;
  bool again = false;
  while (T--) {
    int n;
    cin >> n;
    string dumb;
    getline(cin, dumb);

    if (again) {
      cout << endl;
    }
    again = true;
    string name[25];
    ri {
      getline(cin, name[i]);
      //ppn(name[i]);
    }
    int cnt = 0;
    int vote[1010][1010];
    while (1) {
      string line;
      getline(cin, line);
      //ppn(line);
      stringstream input(line);
      bool found = false;
      ri {
        if (!(input >> vote[cnt][i])) {
          found = true;
          break;
        }
        vote[cnt][i]--;
      }
      if (found) break;
      cnt++;
    }
    //ppn(cnt);
    int ndead = 0;
    bool dead[30] = {0};
    bool found = false;
    string res;
    while (ndead < n && !found) {
      //ppn(ndead);
      res = "";
      int total[30] = {0};
      int nvotes = 0;
      r(i, cnt) {
        r(j, n) {
          if (!dead[vote[i][j]]) {
            total[vote[i][j]]++;
            nvotes++;
            break;
          }
        }
      }
      //ppn(nvotes);
      int nmin = INT_MAX;
      ri {
        if (!dead[i]) {
          nmin = min(nmin, total[i]);
          if (total[i] > nvotes / 2) {
            found = true;
            res += name[i];
            res += "\n";
          }
        }
      }
      //ppn(nmin);
      if (found) {
        //ppn(found);
        break;
      }
      ri {
        if (!dead[i]) {
          if (total[i] == nmin) {
            dead[i] = true;
            ndead++;
            res += name[i];
            res += "\n";
          }
        }
      }
    }

    cout << res;
    //ppn(cnt);
    //ppn(i);
  }
} 

