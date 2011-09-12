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

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

typedef long long ULL;

using namespace std;

int main() {
  ULL n, x, y;
  cin >> n >> x >> y;
  repbe(i, 1, n) {
    ULL num = (y - (n - i));
    if (num < 0) continue;
    ULL div = num / i,
        mod = num % i;
    if ((div == 0 && i - mod > 0) || div <= -1) continue;
    ULL sum = n - i + (i - mod) * div * div + mod * (div + 1) * (div + 1);
    // cout << "sum:" << sum << endl;
    if (sum >= x) {
      rep(j, i - mod) {
        cout << div << endl;
      }
      rep(j, mod) {
        cout << div + 1 << endl;
      }
      rep(j, n - i) {
        cout << 1 << endl;
      }
      return 0;
    }
  }

  cout << "-1" << endl;

  // cout << n << x << y;
}
