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

int val(char c) {
  if (c == 'V') return 0;
  if (c == 'U') return 1;
  if (c == 'C') return 2;
  if (c == 'D') return 3;
  return -1;
}
 
int main() {
  int n;
  cin >> n;
  cout << "COWCULATIONS OUTPUT" << endl;
  while (n--) {
    int v[3] = {0};
    string s;
    r(i, 3) {
      cin >> s;
      r(j, s(s)) {
        int d = val(s[j]);
        v[i] *= 4;
        v[i] += d;
      }
      if (i == 1) {
        //cout << v[0] << " " << v[1] << endl;
        r(i, 3) {
          char c;
          cin >> c;
          if (c == 'A') v[1] += v[0];
          if (c == 'L') v[1] *= 4;
          if (c == 'R') v[1] /= 4;
          //cout << v[1] << ' ';
        }
      }
      if (i == 2) {
        cout << (v[1] == v[2] ? "YES" : "NO") << endl;
      }
    }
  }
  cout << "END OF OUTPUT" << endl;
} 

