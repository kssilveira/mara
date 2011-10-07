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

int base = 5347;
 
int main() {
  int n;
  string s;
  while (cin >> n >> s) {
    map<int, int> res;
    int pot[20];
    unsigned int hash = 0;
    pot[0] = 1;
    r(i, n) {
      hash = hash * base + s[i];
      pot[i + 1] = pot[i] * base;
    }
    res[hash]++;
    int nmax = 1;
    int ni = 0;
    //cout << "hash: " << hash
      //<< " nmax: " << nmax
      //<< " ni: " << ni << endl;
    rb(i, n, s(s)) {
      hash -= s[i - n] * pot[n - 1];
      hash = hash * base + s[i];
      int cur = ++res[hash];
      if (cur > nmax) {
        nmax = cur;
        ni = i - n + 1;
      }
    //cout << "hash: " << hash
      //<< " nmax: " << nmax
      //<< " ni: " << ni << endl;
    }
    rb(i, ni, ni + n) {
      cout << s[i];
    }
    cout << endl;
  }
} 

