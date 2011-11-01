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
  r(Case, T) {
    int c;
    cin >> c;
    int n = c;
    map<string, int> ind;
    string back[110];
    r(i, c) {
      string name;
      cin >> name;
      ind[name] = i;
      back[i] = name;
    }
    int t;
    cin >> t;
    vector<pair<int, pair<int, int> > > graph[110];
    r(i, t) {
      int ti;
      cin >> ti;
      int lasthour;
      int lastid = -1;
      r(j, ti) {
        int hour;
        string name;
        cin >> hour >> name;
        int id = ind[name];
        if (lastid != -1) {
          graph[lastid].push_back(make_pair(lasthour, make_pair(id, hour)));
        }
        lastid = id;
        lasthour = hour;
      }
    }
    ri {
      sort(all(graph[i]));
      reverse(all(graph[i]));
    }
    int starthour;
    string startname, endname;
    cin >> starthour >> startname >> endname;
    //ppn(startname); ppn(endname);
    int start = ind[startname],
        end = ind[endname];

    int dp[2500][110];
    r(i, 2500) {
      r(j, 110) {
        dp[i][j] = -1;
      }
    }

    r(i, s(graph[start])) {
      int lasthour = graph[start][i].first;
      if (lasthour >= starthour) {
        int next = graph[start][i].second.first,
            hour = graph[start][i].second.second;
        dp[hour][next] = max(dp[hour][next], lasthour);
      }
    }

    r(i, 2500) {
      r(j, n) {
        if (dp[i][j] == -1) continue;
        r(k, s(graph[j])) {
          int lasthour = graph[j][k].first;
          if (lasthour < i) break;
          int next = graph[j][k].second.first,
              hour = graph[j][k].second.second;
          dp[hour][next] = max(dp[hour][next], dp[i][j]);
        }
      }
    }

    bool found = false;
    int starttime, endtime;
    r(i, 2500) {
      if (dp[i][end] != -1) {
        found = true;
        starttime = dp[i][end];
        endtime = i;
        break;
      }
    }

    cout << "Scenario " << Case + 1 << endl;
    //ppn(start); ppn(end);
    if (!found) {
      cout << "No connection" << endl;
    } else {
      printf("Departure %04d %s\n", starttime,
          back[start].c_str());
      printf("Arrival   %04d %s\n",
          endtime,
          back[end].c_str());
    }
    cout << endl;
  }
} 

