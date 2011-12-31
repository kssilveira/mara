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

int pot[11];

string solve(int n3, int n2, int k, int min3, int cur, int ind) {
  //printf("solve(%d, %d, %d, %d, %d)\n", n3, n2, k, min3, cur);
  if (k == 0) return "0";

  string res;

  if (min3 > 0 && cur % 2) {
    string next = solve(n3 - 1, n2, k - 1, min3 - 1,
        (cur + 3 * pot[ind]) / 2, ind + 1);
    if (!next.empty()) {
      res = next + '3';
      return res;
    }
  }
  if (n2 > 0 && !(cur % 2)) {
    string next = solve(n3, n2 - 1, k - 1, min3, (cur + 2 * pot[ind]) / 2,
        ind + 1);
    if (!next.empty()) {
      res = next + '2';
      return res;
    }
  }
  if (n3 > 0 && cur % 2) {
    string next = solve(n3 - 1, n2, k - 1, min3 - 1,
        (cur + 3 * pot[ind]) / 2, ind + 1);
    if (!next.empty()) {
      res = next + '3';
      return res;
    }
  }

  return res;
}
 
int main() {
  int n, m, k;

  pot[0] = 1;

  r(i, 10) {
    pot[i + 1] = pot[i] * 5;
  }

  while (cin >> n >> m >> k) {

  r(K, 100) {
    r(N, K) {
    int n = N, m = K - n, k = K;

    if (k == 0) {
      cout << endl;
      continue;
    }

    if (k > n + m || m == 0) {
      cout << "Impossible." << endl;
      continue;
    }

    //*
    k--;
    m--;

    int min3 = max(k - m, 0);
    string resa = solve(n, m, k, min3, 1, 1);
    if (resa.empty()) {
      continue;  // ERASE!!!
      cout << "Impossible." << endl;
    } else {
      printf("(%d %d %d)\n", n, m, k);

      cout << resa.substr(1) + '2' << endl;
    }

    k++;
    m++;//*/

    /*
  string res = "23232";
  int cnt[2] = {3, 2};
  if (k < 5) {
    for (int i = 4; i >= k; i--) {
      int cur = res[i] - '2';
      cnt[cur]--;
    }
    res = res.substr(0, k);
  }

  rb(i, 5, k) {
    int cur = 1 - (((i - 5) % 4) / 2);
    res += '2' + cur;
    cnt[cur]++;
  }

  reverse(all(res));

  if (cnt[0] <= m && cnt[1] <= n) {
    //assert(res == resa.substr(1) + '2');
    cout << res << endl;
  } else {
    //assert(resa.empty());
    cout << "Impossible." << endl;
  }//*/

  }
    }}
} 

