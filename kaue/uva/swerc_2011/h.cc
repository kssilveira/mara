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
  int k, n;
  while (scanf("%d%d", &k, &n) && k > 0) {
    char name[1010][30];
    int graph[1010][1010] = {{0}};
    ri {
      scanf("%s", name[i]);
      r(j, k) {
        int v;
        scanf("%d", &v);
        v--;
        graph[i][v]++;
      }
    }
    bool invalid[1010] = {0};
    int cnt[1010] = {0};
    ri {
      rj {
        if (graph[i][j]) {
          cnt[j]++;
        }
        if (graph[i][j] > 1) {
          //printf("%d %d = %d\n", i, j, graph[i][j]);
          invalid[j] = true;
        }
        if (graph[i][j] && !strcmp(name[i], name[j])) {
          invalid[j] = true;
        }
      }
    }
    ri {
      if (cnt[i] != k) {
        invalid[i] = true;
      }
    }
    int res = 0;
    ri {
      if (invalid[i]) {
        res++;
      }
    }
    if (res == 0) {
      printf("NO PROBLEMS FOUND\n");
    } else if (res == 1) {
      printf("1 PROBLEM FOUND\n");
    } else {
      printf("%d PROBLEMS FOUND\n", res);
    }
  }
} 

