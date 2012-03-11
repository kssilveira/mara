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
#define mp make_pair
#define nl cout << endl
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
  int n, k;
  cin >> n >> k;
  ll c[1010], t[1010];
  int stool = 0;
  vector<pair<ll,ll> > v, other;
  ll nmin = INT_MAX;
  ri {
    cin >> c[i] >> t[i];

    if (c[i] < nmin) nmin = c[i];
    
    if (t[i] == 1) {
      stool++;
      v.push_back(make_pair(c[i], i));
    } else {
      other.push_back(make_pair(c[i], i));
    }
  }
  sort(all(v));
  reverse(all(v));
  r(i, s(v)) {
    c[i] = v[i].first;
  }
  //sort(c, c + n);
  //reverse(c, c + n);
   ll res = 0, cent = 0;
  vector<int> alone, rest;
  r(i, s(v)) {
    if (i < stool && i < k - 1) {
      res += c[i] / 2;
      cent += c[i] % 2;
      alone.push_back(v[i].second + 1);
    } else {
      res += c[i];
      rest.push_back(v[i].second + 1);
    }
  }

  r(i, s(other)) {
    res += other[i].first;
    rest.push_back(other[i].second + 1);
  }

  if (stool >= k) {
    res -= nmin;
    res += nmin / 2;
    cent += nmin % 2;
  }
  
  res += cent / 2;
  cent %= 2;

  //printf("%Li.%Li\n", res, 5 * cent);
  cout << res << '.' << 5 * cent << endl;

  r(i, s(alone)) {
    printf("1 %i\n", alone[i]);
  }

  int miss = k - s(alone) - 1;

  r(i, miss) {
    printf("1 %i\n", rest[i]);
  }

  if (s(rest) - miss > 0) {
    printf("%i", s(rest) - miss);
    rb(i, miss, s(rest)) {
      printf(" %i", rest[i]);
    }
    printf("\n");
  }
} 

