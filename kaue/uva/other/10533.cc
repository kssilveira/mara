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

int dp[1000010] = {0};
bitset<1000010> isnotprime;
bitset<1000010> isnotgood;
 
int main() {

  isnotprime[0] = isnotprime[1] = true;
  r(i, 1000010 / 2) isnotprime[2 * i] = true;
  isnotprime[2] = false;
  dp[2] = 1;
  for (int i = 3; i < 1000010; i += 2) {
    dp[i] = dp[i - 1];
    dp[i + 1] = dp[i];
    if (isnotprime[i]) continue;
    for (int j = i + i; j < 1000010; j += i) {
      isnotprime[j] = true;
    }
    int t = i;
    int sum = 0;
    while (t) {
      sum += t % 10;
      t /= 10;
    }
    if (isnotprime[sum]) isnotgood[i] = true;
    if (!isnotgood[i]) {
      dp[i]++;
      dp[i + 1] = dp[i];
    }
  }

  isnotgood |= isnotprime;

  /*
  r(i, 30) {
    if (!isnotprime[i]) {
      cout << i << ' ';
    }
  }
  cout << endl;//*/

  /*
  r(i, 30) {
    if (!isnotgood[i]) {
      cout << i << ' ';
    }
  }
  cout << endl;//*/

  /*
  r(i, 30) {
    cout << dp[i] << ' ';
  }
  cout << endl;//*/

  int n;
  cin >> n;
  ri {
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    //ppn(t1); ppn(t2);
    printf("%d\n", dp[t2] - dp[t1 - 1]);
  }
} 

