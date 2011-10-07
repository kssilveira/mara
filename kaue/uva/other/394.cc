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
  int n, r;
  cin >> n >> r;
  vs names;
  vi bases, sizes, dims;
  map<string, int> indexes;
  vector<vi> lowers(n), uppers(n);
  vi C[30];
  r(i, n) {
    string name;
    int base, size, d;
    cin >> name >> base >> size >> d;
    names.push_back(name);
    indexes[name] = i;
    bases.push_back(base);
    sizes.push_back(size);
    dims.push_back(d);
    r(j, d) {
      int lower, upper;
      cin >> lower >> upper;
      lowers[i].push_back(lower);
      uppers[i].push_back(upper);
    }
    int cur = i;
    int B = bases[cur];
    int D = dims[cur];
    C[cur] = vi(D + 1);
    C[cur][D] = sizes[cur];
    for (int j = D - 1; j >= 1; j--) {
      C[cur][j] =
        C[cur][j + 1] * (uppers[cur][j] - lowers[cur][j] + 1);
    }
    C[cur][0] = B;
    r(j, D) {
      C[cur][0] -= C[cur][j + 1] * lowers[cur][j];
    }
  }
  r(i, r) {
    string name;
    cin >> name;
    cout << name << "[";
    int cur = indexes[name];
    vi inds;
    int D = dims[cur];
    r(j, dims[cur]) {
      if (j) {
        cout << ", ";
      }
      int ind;
      cin >> ind;
      cout << ind;
      inds.push_back(ind);
    }
    int res = C[cur][0];
    r(j, D) {
      res += C[cur][j + 1] * inds[j];
    }
    cout << "] = " << res << endl;
  }
} 

