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

list<int> cyc;
int graph[55][55];

void euler(list<int>::iterator i, int u) {
  r(v, 55) {
    while (graph[u][v]) {
      //printf("euler(%d) => %d\n", u, v);
      graph[u][v]--;
      graph[v][u]--;
      euler(cyc.insert(i, u), v);
    }
  }
}
 
int main() {
  int T;
  cin >> T;
  bool second = false;
  r(tT, T) {
    if (second) cout << endl;
    second = true;
    int n;
    cin >> n;
    int v[1010][2];
    int cnt[55] = {0};
    memset(graph, 0, sizeof(graph));
    int start = 0;
    ri {
      cin >> v[i][0] >> v[i][1];
      cnt[v[i][0]]++;
      cnt[v[i][1]]++;
      graph[v[i][0]][v[i][1]]++;
      graph[v[i][1]][v[i][0]]++;
      start = v[i][0];
      //ppn(v[i][0]); ppn(v[i][1]);
    }

    bool invalid = false;
    r(i, 55) {
      if (cnt[i] % 2) {
        invalid = true;
        break;
      }
    }

    /*
    r(i, 7) {
      r(j, 7) {
        cout << graph[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/

    cyc.clear();
    euler(cyc.begin(), start);
    //ppn(cyc.size());

    if (s(cyc) != n) invalid = true;

    cout << "Case #" << tT + 1 << endl;

    if (!invalid) {
      int last = start;
      for (list<int>::iterator i = cyc.begin();
          i != cyc.end(); ++i) {
        cout << last << ' ' << *i << endl;
        last = *i;
      }
    } else {
      cout << "some beads may be lost" << endl;
    }
  }
} 

