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
  int n;
  bool sec = false;
  int Case = 0;
  while (cin >> n && n) {
    Case++;
    if (sec) cout << endl;
    sec = true;
    map<string, int> ind;
    string back[110];
    vector<int> graph[110];
    ri {
      string name;
      cin >> name;
      ind[name] = i + 1;
      back[i + 1] = name;
    }
    int r;
    cin >> r;
    r(i, r) {
      string a, b;
      cin >> a >> b;
      int ida = ind[a],
          idb = ind[b];
      graph[ida].push_back(idb);
      graph[idb].push_back(ida);
    }
    int cnt[110] = {0};
    int res = 0;
    vector<string> what;
    r(i, n + 1) {
      bool gone[110] = {0};
      gone[i] = true;
      rb(j, 1, n + 1) {
        if (!gone[j]) {
          cnt[i]++;
          queue<int> q;
          q.push(j);
          while (!q.empty()) {
            int cur = q.front();
            q.pop();
            r(i, s(graph[cur])) {
              int next = graph[cur][i];
              if (!gone[next]) {
                gone[next] = true;
                q.push(next);
              }
            }
          }
        }
      }
      if (cnt[i] > cnt[0]) {
        res++;
        what.push_back(back[i]);
      }
    }
    sort(all(what));
    cout << "City map #" << Case << ": " << res
      << " camera(s) found" << endl;
    r(i, res) {
      cout << what[i] << endl;
    }
  }
} 

