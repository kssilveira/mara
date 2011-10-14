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
 
char s[5010];

bool gone[5010], processed[5010];
bool graph[5010][5010];
int n;

vector<int> res;

bool dfs(int cur) {
  //ppn(cur);
  if (gone[cur]) {
    res.push_back(cur);
    return true;
  }
  gone[cur] = true;
  ri {
    if (graph[cur][i] && !processed[i]) {
      if (dfs(i)) {
        res.push_back(cur);
        return true;
      }
    }
  }
  processed[cur] = true;
  return false;
}

int main() {
  cin >> n;
  memset(graph, 0, sizeof(graph));
  ri {
    scanf("%s", s);
    rj {
      if (s[j] == '1') {
        graph[i][j] = 1;
      }
    }
  }
  //int m = n;
  //pm(graph);

  memset(processed, 0, sizeof(processed));
  ri {
    res.clear();
    memset(gone, 0, sizeof(gone));
    if (!processed[i] && dfs(i)) {
      res.push_back(res[1]);
      int n = s(res);
      //pv(res);
      /*
      r(i, n - 1) {
        r(j, n) {
          if (graph[res[i]][j] && graph[j][res[i + 1]]) {
            cout <<
              res[i] + 1 << " " <<
              j + 1 << " " <<
              res[i + 1] + 1 << endl;
            return 0;
          }
        }
      }//*/

      r(i, n) {
        rb(j, i + 1, n) {
          rb(k, j + 1, n) {
            if (graph[res[i]][res[k]] && graph[res[k]][res[j]] &&
                graph[res[j]][res[i]]) {
              cout << res[i] + 1 << " " <<
                res[k] + 1 << " " <<
                res[j] + 1 << endl;
              return 0;
            }
          }
        }
      }
        //ppn(i);
        //if (graph[res[i]][res[i + 2]]) {
          //cout <<
            //res[i] + 1 << " " <<
            //res[i + 2] + 1 << " " <<
            //res[i + 1] + 1 << endl;
          //break;
        //}
      //}
      //cout << "batata" << endl;
      return 0;
    }
  } 
  cout << -1 << endl;
}
