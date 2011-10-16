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

int to_i(const string& s) {
  int res = 0;
  r(i, s(s)) {
    res *= 10;
    res += s[i] - '0';
  }
  return res;
}

void to_s(int x, string* s) {
  int n = (int) s->size();
  while (x > 0) {
    (*s)[n - 1] = (x % 10) + '0';
    n--;
    x /= 10;
  }
}

bool pal(const string& s) {
  int n = s(s);
  r(i, n / 2) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }
  }
  return true;
}
 
int main() {
  string s;
  while (cin >> s && s != "0") {
    int res = 0;
    while (!pal(s)) {
      //ppn(s);
      to_s(1 + to_i(s), &s);
      res++;
    }
    cout << res << endl;
  }
} 

