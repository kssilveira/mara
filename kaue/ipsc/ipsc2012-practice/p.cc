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

vi rleft, rright;

bitset<3500000> gone;
int res[3500000];

int main() {
  int T;
  cin >> T;
  while (T--) {
    //printf("T: %d\n", T);
    fprintf(stderr, "T: %d\n", T); fflush(stderr);
    rleft.clear(); rright.clear();
    gone.reset();
    memset(res, 0, sizeof(res));
    int n;
    cin >> n;
    int v[15010];
    ull sum = 0;
    int imax = 0;
    ri {
      cin >> v[i];
      sum += v[i];
      if (v[i] > v[imax]) {
        imax = i;
      }
    }
    ull target = sum / 2;
    /*
    int cnt = 0;
    ull prod = n * target;
    while (prod > 0) {
      prod /= 10;
      cnt++;
    }
    cout << "target: " << target << " n: " << n << " n*target: " << n * target << " log10(n * target): " << cnt << endl;//*/

    sum -= v[imax];
    swap(v[imax], v[n - 1]);
    n--;
    gone[0] = true;
    res[0] = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (i % 1000 == 0) { fprintf(stderr, "i: %d\n", i); fflush(stderr); }
      for (int j = target; j - v[i] >= 0; j--) {
        if (!gone[j] && gone[j - v[i]]) {
          gone[j] = true;
          res[j] = i;
        }
      }
    }

    /*
    cout << "gone: ";
    for (int j = 0; j <= target; j++) {
      printf("%d", gone[j] ? 1 : 0);
    }
    cout << endl;//*/

    for (int j = target; j >= 0; j--) {
      if (gone[j]) {
        while (j) {
          int cur = res[j];
          rleft.push_back(cur);
          j = j - v[cur];
        }
        sort(rleft.begin(), rleft.end());
        int cur = 0, i = 0;
        while (cur < s(rleft)) {
          while (cur < s(rleft) && i == rleft[cur]) {
            cur++;
            i++;
          }
          if (cur < s(rleft)) {
            while (i < rleft[cur]) {
              rright.push_back(i);
              i++;
            }
          }
        }
        while (i < n) {
          rright.push_back(i);
          i++;
        }


        ull sleft = 0, sright = 0;
        for (int i = 0; i < s(rleft); i++) {
          sleft += v[rleft[i]];
        }
        for (int j = 0; j < s(rright); j++) {
          sright += v[rright[j]];
        }

        assert(sleft <= target && sright <= target && s(rleft) + s(rright) == n);

          cout << rleft.size();
          for (int i = 0; i < s(rleft); i++) {
            cout << ' ';
            if (rleft[i] == imax) {
              rleft[i] = n;
            }
            cout << rleft[i] + 1;
          }
          cout << endl;
          cout << rright.size();
          for (int i = 0; i < s(rright); i++) {
            cout << ' ';
            if (rright[i] == imax) {
              rright[i] = n;
            }
            cout << rright[i] + 1;
          }
          cout << endl;

          break;
      }
    }

    /*
    bool done = false;
    for (int out = 0; out < n && !done; out++) {
      for (int mask = 0; mask < (1 << n) && !done; mask++) {
        ull left = 0, right = 0;
        ri {
          if (i == out) { continue; }
          if (mask & (1 << i)) {
            left += v[i];
          } else {
            right += v[i];
          }
        }
        if (left <= target && right <= target) {
          done = true;
          ri {
            if (i == out) { continue; }
            if (mask & (1 << i)) {
              rleft.push_back(i);
            } else {
              rright.push_back(i);
            }
          }
          cout << rleft.size();
          for (int i = 0; i < s(rleft); i++) {
            cout << ' ';
            cout << rleft[i] + 1;
          }
          cout << endl;
          cout << rright.size();
          for (int i = 0; i < s(rright); i++) {
            cout << ' ';
            cout << rright[i] + 1;
          }
          cout << endl;
        }
      }
    }
    //*/
  }
} 

