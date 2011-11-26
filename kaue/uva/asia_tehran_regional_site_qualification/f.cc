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
#include <iomanip>
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
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int row[1010], col[1010], tab[1010][1010] = {{0}};
    memset(tab, 0, sizeof(tab));
    ri {
      scanf("%d", &row[i]);
    }
    rim {
      scanf("%d", &col[i]);
    }
    sort(row, row + n);
    reverse(row, row + n);
    sort(col, col + m);
    reverse(col, col + m);
    int res = 0;
    rjm {
      sort(row, row + n);
      reverse(row, row + n);
      int i = 0;
      while (col[j] && i < n) {
        for (; i < n; i++) {
          if (row[i] > 0) {
            row[i]--;
            col[j]--;
            res++;
            i++;
            break;
          }
        }
      }
      res += col[j];
    }
    ri {
      res += row[i];
    }
    /*
    ri {
      r(j, row[i]) {
        tab[i][j] = 1;
      }
    }
    rjm {
      r(i, col[j]) {
        tab[i][j] += 2;
      }
    }//*/
    /*
    ri {
      rjm {
        cout << tab[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/
    //int res = 0;
    /*
    ri {
      rjm {
        if (tab[i][j] != 0) res++;
      }
    }//*/
    printf("%d\n", res);
  }
} 

