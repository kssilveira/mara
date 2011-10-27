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
  bool second = false;
  string line;
  getline(cin, line);
  getline(cin, line);
  while (T--) {
    if (second) cout << endl;
    second = true;
    bool present[110] = {0};
    bool solved[110][11] = {{0}};
    int count[110] = {0};
    int total[110] = {0};
    int tries[110][11] = {{0}};
    while (getline(cin, line) && !line.empty()) {
      //ppn(line);
      istringstream input(line);
      int contestant, problem, time;
      char l;
      input >> contestant >> problem >> time >> l;
      //ppn(contestant); ppn(problem); ppn(time); ppn(l);
      present[contestant] = true;
      if (l == 'C' && solved[contestant][problem] == false) {
        solved[contestant][problem] = true;
        count[contestant]++;
        total[contestant] += tries[contestant][problem] * 20 + time;
      } else if (l == 'I') {
        tries[contestant][problem]++;
      }
    }

    vector<pair<int, pair<int, int> > > v;
    rb(i, 1, 101) {
      if (!present[i]) continue;
      v.push_back(make_pair(-count[i], make_pair(-total[i], i)));
    }
    sort(all(v));
    r(i, s(v)) {
      cout << v[i].second.second << ' ' << -v[i].first << ' '
        << -v[i].second.first << endl;
    }
  }
} 

