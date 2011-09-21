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
  int m, n;
  while (scanf("%d%d", &m, &n) && m != -1) {
    ld val = m / (ld) n;
    int k = val * 20 + 0.5;
    char res[21] = {0};
    r(i, 20) res[i] = '-';
    r(i, k) res[i] = '*';
    int p = val * 100 + 0.5;
    // ppn(p);
    // ppn(k);
    int cnt = 0;
    char s[21] = "";
    s[cnt++] = '%';
    if (p == 0) {
      s[cnt++] = '0';
    }
    while (p) {
      s[cnt++] = (p % 10) + '0';
      p /= 10;
    }
    r(i, cnt) {
      res[(20 - cnt + 1) / 2 + i] = s[cnt - 1 - i];
    }
    cout << res << endl;
  }
} 

