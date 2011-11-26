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
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

const int MAX = 660000;
bitset<MAX> isnotprime;
vector<int> primes;
 
int main() {
  primes.push_back(2);
  for (int i = 3; i / 2 < MAX; i += 2) {
    if (!isnotprime[i / 2]) {
      primes.push_back(i);
      for (int j = i + i; j / 2 < MAX; j += i) {
        if (j % 2) {
          isnotprime[j / 2] = 1;
        }
      }
    }
  }
  /*
  r(i, s(primes)) {
    cout << primes[i] << ' ';
  }
  cout << endl;//*/
  //ppn(s(primes));

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int x[100010], s[100010] = {0};
    r(i, n) {
      x[i] = primes[i] % m;
    }
    /*
    r(i, n) {
      cout << x[i] << ' ';
    }
    cout << endl;//*/
    s[0] = 1;
    int res = 1;
    rb(i, 1, n) {
      s[i] = 1;
      int k = i - 1;
      while (k >= 0 && x[i] >= x[k]) {
        s[i] += s[k];
        k -= s[k];
      }
      res += s[i];
      res %= m;
    }
    /*
    r(i, n) {
      cout << s[i] << ' ';
    }
    cout << endl;//*/
    printf("%d\n", res);
  }
} 

