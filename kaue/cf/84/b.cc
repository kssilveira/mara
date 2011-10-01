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

bool islucky(int i) {
  if (i == 0) return false;
  while (i > 0) {
    int d = i % 10;
    if (d != 4 && d != 7) return false;
    i /= 10;
  }
  return true;
}
 
int main() {
  set<int> lucky;
  for (int i = 4; i <= 100000; i++) {
    //ppn(i);
    if (islucky(i)) {
      lucky.insert(i);
    }
  }
  //int n = s(lucky);
  //ppn(n);
  //pv(lucky);
  char last = 'a';
  string res;
  int n;
  cin >> n;
  int ind[30] = {0};
  ri {
    bool found = false;
    for (int j = 0; j < last - 'a'; j++) {
      int dist = i - ind[j];
      if (lucky.find(dist) != lucky.end()) {
        res += ('a' + j);
        found = true;
        ind[j] = i;
      }
    }
    if (!found) {
      res += last;
      ind[last - 'a'] = i;
      last++;
    }
  }
  cout << res << endl;
} 

