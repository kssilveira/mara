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

int val[110], like[110], gone[110], graph[110][110], used[110], neg[110];
int n;

void dfs(int cur) {
  gone[cur] = true;
  if (used[cur]) {
    val[cur] = 0;
    neg[cur] = 0;
    return;
  }
  val[cur] = like[cur];
  if (like[cur] < 0) {
    neg[cur] = -like[cur];
  } else {
    neg[cur] = 0;
  }
  ri {
    if (graph[cur][i]) {
      if (!gone[i]) {
        dfs(i);
        val[cur] += val[i];
        neg[cur] += neg[i];
      }
    }
  }
}
 
void mark(int cur) {
  used[cur] = true;
  ri {
    if (graph[cur][i]) {
      if (!used[i]) {
        mark(i);
      }
    }
  }
}
 
int usedbak[110][110];
void bt(int cur, int& best, int depth) {
  if (depth != 0) {
    best = max(best, cur);
  }
  /*
  int rest = 0;
  ri {
    if (!used[i] && like[i] > 0) {
      rest += like[i];
    }
  }
  if (rest + cur < best) return;//*/

  ri {
    if (used[i]) continue;
    memset(gone, 0, sizeof(gone));
    memset(val, 0, sizeof(val));
    dfs(i);
    //if (val[i] > 0) {
      memcpy(usedbak[depth], used, sizeof(used));
      mark(i);
      bt(cur + val[i], best, depth + 1);
      memcpy(used, usedbak[depth], sizeof(used));
    //}
  }
}

int main() {
  int T;
  cin >> T;
  r(Case, T) {
    cin >> n;
    memset(graph, 0, sizeof(graph));

    ri {
      cin >> like[i];
      int deg;
      cin >> deg;
      r(j, deg) {
        int v;
        cin >> v;
        v--;
        graph[i][v] = 1;
      }
    }


    int res = -1;
    /*
    memset(used, 0, sizeof(used));
    ri {
      int nmax = -1, maxi;
      int nmin = INT_MAX;
      ri {
        memset(gone, 0, sizeof(gone));
        memset(val, 0, sizeof(val));
        memset(neg, 0, sizeof(neg));
        dfs(i);

        if (val[i] > 0 && (neg[i] < nmin || (neg[i] == nmin &&
                val[i] > nmax))) {
          nmin = neg[i];
          maxi = i;
          nmax = val[i];
        }
        if (val[i] == 0 && nmin == INT_MAX) {
          nmin = neg[i];
          maxi = i;
          nmax = val[i];
        }

        //if (val[i] > nmax) {
          //nmax = val[i];
          //maxi = i;
        //}
      }
      if (nmax > 0) {
        res = max(res, 0);
        res += nmax;
        mark(maxi);
      } else if (nmax == 0) {
        res = max(res, 0);
        break;
      } else {
        break;
      }
    }//*/

    int best = res;
    memset(used, 0, sizeof(used));
    bt(0, best, 0);
    //assert(best == res);
    res = best;

    printf("Case #%d: ", Case + 1);
    if (res < 0) {
      printf("Alas, sultan can't invite anyone!\n");
    } else {
      printf("%d\n", res);
    }
  }
} 

