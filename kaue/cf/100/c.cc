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

#define pb push_back
#define nl cout << endl
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  ri {
    int r;
    cin >> r;
    mp[r]++;
  }
  priority_queue<pair<int, int> > q;
  for (map<int, int>::iterator it = mp.begin();
      it != mp.end();
      ++it) {
    int a = it->second, b = it->first;
    //ppn(a); ppn(b);
    q.push(make_pair(a, b));
  }
  int res = 0;
  ostringstream out;
  while (q.size() >= 3) {
    res++;
    int cur[3][2];
    int v[3];
    r(i, 3) {
      cur[i][0] = q.top().second;
      cur[i][1] = q.top().first;
      q.pop();
      v[i] = cur[i][0];
    }
    sort(v, v + 3);
    reverse(v, v + 3);
    r(i, 3) {
      if (i) out << ' ';
      out << v[i];
    }
    out << endl;
    //ppn(cur[0][0]); ppn(cur[0][1]);
    r(i, 3) {
      cur[i][1]--;
      if (cur[i][1]) {
        q.push(make_pair(cur[i][1], cur[i][0]));
      }
    }
  }
  cout << res << endl;
  cout << out.str();
} 

