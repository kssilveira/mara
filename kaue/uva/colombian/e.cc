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
 
char line[10000];

const int INF = 100 * 100 * 100;

int main() {
  int n;
  while (cin >> n && n > 0) {
    bool graph[110][110] = {{0}};
    r(i, n) {
      //ppn(i);
      int k;
      cin >> k;
      cin.getline(line, 10000);
      stringstream input(line);
      while (input >> k) {
        k--;
        graph[i][k] = 1;
        //ppn(k);
      }
      graph[i][i] = 1;
    }

    int dist[110][110] = {{0}};
    r(i, n) {
      r(j, n) {
        dist[i][j] = graph[i][j];
        if (!graph[i][j]) dist[i][j] = INF;
      }
      dist[i][i] = 0;
    }

        r(k, n) {
    r(i, n) {
      r(j, n) {
            dist[i][j] = min(dist[i][j],
                dist[i][k] + dist[k][j]);
        }
      }
    }

    memset(graph, 0, sizeof(graph));
    r(i, n) {
      //ppn(i);
      int k;
      cin >> k;
      cin.getline(line, 10000);
      stringstream input(line);
      while (input >> k) {
        k--;
        graph[i][k] = 1;
        //ppn(k);
      }
      graph[i][i] = 1;
    }

    int dist2[110][110] = {{0}};
    r(i, n) {
      r(j, n) {
        dist2[i][j] = graph[i][j];
        if (!graph[i][j]) dist2[i][j] = INF;
      }
      dist2[i][i] = 0;
    }

    /*
    p("dist2:\n");
    r(i, n) {
      r(j, n) {
        cout <<dist2[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/

    /*
    p("graph\n");
    r(i, n) {
      r(j, n) {
        cout << graph[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/

        r(k, n) {
    r(i, n) {
      r(j, n) {
        //ppn(i);
        //ppn(j);
        //ppn(k);
        //ppn(graph[i][k]);
        //ppn(graph[k][j]);
        //ppn(dist2[i][j]);
            dist2[i][j] = min(dist2[i][j],
                dist2[i][k] + dist2[k][j]);
            //ppn(dist2[i][j]);
        }
      }
    }

    int a, b;
    cin >> a >> b;
    bool found = false;

    /*
    r(i, n) {
      r(j, n) {
        cout << dist[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/

    /*
    p("dist2 after\n");
    r(i, n) {
      r(j, n) {
        cout << dist2[i][j] << ' ';
      }
      cout << endl;
    }//*/

    /*
    p("graph after\n");
    r(i, n) {
      r(j, n) {
        cout << graph[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/

    r(i, n) {
      r(j, n) {
        if (dist2[i][j] > dist[i][j] * a + b) {
          found = true;
          break;
        }
      }
      if (found) break;
    }

    if (found) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }

  }
} 

