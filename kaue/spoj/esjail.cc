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
#define MAX 100010

int key[MAX];
bool cango[MAX], locked[MAX];
vi graph[MAX];
 
int main() {
  int n, k, m;
  while (scanf("%d%d%d", &n, &k, &m) && n != -1) {
    memset(key, 0, sizeof(key));
    memset(cango, 0, sizeof(cango));
    memset(locked, 0, sizeof(locked));

    r(i, k) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      key[a] = b;
      locked[b] = 1;
    }
    rim {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    /*
    ri {
      int m = s(graph[i]);
      rjm {
        p(graph[i][j]);
      }
      pl;
    }//*/
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
      int cur = s.top(); s.pop();
      //ppn(cur);
      int next = key[cur];
      if (next) {
        locked[next] = 0;
        if (cango[next]) {
          s.push(next);
        }
      }
      {
        int n = s(graph[cur]);
        ri {
          next = graph[cur][i];
          //ppn(next);
          if (!cango[next]) {
            cango[next] = 1;
            if (!locked[next]) {
              s.push(next);
            }
          }
        }
      }
      
      if(cango[n - 1]) break;
    }

    printf("%s\n", cango[n - 1] ? "Y" : "N");

    ri {
      graph[i].clear();
    }
  }
} 

