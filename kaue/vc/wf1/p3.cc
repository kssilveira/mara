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

#define nl printf("\n")
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

vector<int> cycle[100010];
bitset<100010> gone;
int v[100010];
int rest[4][100010][3];

void find(int cur, int ncycle) {
  gone[cur] = true;
  int next = v[cur];
  //cycle[ncycle][deg[ncycle]++] = cur;
  cycle[ncycle].push_back(cur);
  if (!gone[next]) {
    find(next, ncycle);
  }
}
 
int main() {
  int n;
  cin >> n;
  ri {
    cin >> v[i];
    v[i]--;
  }
  gone.reset();
  int ncycle = 0;
  ri {
    if (!gone[i]) {
      cycle[ncycle].clear();
      find(i, ncycle);
      ncycle++;
    }
  }
  int res = 0;
  {
    int cnt[4] = {0};
    r(i, ncycle) {
      res += s(cycle[i]) / 4;
      int rest = s(cycle[i]) % 4;
      cnt[rest]++;
    }
    int equal = min(cnt[2], cnt[3]);
    res += equal;
    cnt[2] -= equal;
    cnt[3] -= equal;
    res += (cnt[2] + 1) / 2;
    res += 2 * (cnt[3] / 3) + (cnt[3] % 3);
  }
  cout << res << endl;
  int tot[4] = {0};
  r(i, ncycle) {
    int m = s(cycle[i]);
    if (m >= 4) {
      int j;
      for (j = 0; j + 4 <= m; j += 5) {
        int cnt = 5;
        if (j + cnt > m) cnt = 4;

        cout << cnt << endl;
        r(k, cnt) {
          if (k) cout << ' ';
          cout << cycle[i][j + k] + 1;
        }
        nl;
        r(k, cnt - 1) {
          cout << cycle[i][j + k + 1] + 1 << ' ';
        }
        cout << cycle[i][j] + 1;
        nl;
        swap(cycle[i][j], cycle[i][j + cnt - 1]); // TESTAR
        j--;
      }
      int other = m - j;
      if (other > 1) {
        r(k, other) {
          rest[other][tot[other]][k] = cycle[i][j + k] + 1;
        }
        tot[other]++;
      }
    } else if (m > 1) {
      int other = m;
      int j = 0;
        r(k, other) {
          rest[other][tot[other]][k] = cycle[i][j + k] + 1;
        }
        tot[other]++;
    }
  }
  r(i, tot[2]) {
    if (i >= tot[3]) {
      if (i + 1 < tot[2]) {
        cout << 4 << endl;
        cout << rest[2][i][0] << ' ' << rest[2][i][1] << ' ' <<
          rest[2][i + 1][0] << ' ' << rest[2][i + 1][1] << endl;
        cout << rest[2][i][1] << ' ' << rest[2][i][0] << ' ' <<
          rest[2][i + 1][1] << ' ' << rest[2][i + 1][0] << endl;
        i++;
      } else {
        cout << 2 << endl;
        cout << rest[2][i][0] << ' ' << rest[2][i][1] <<
          endl;
        cout << rest[2][i][1] << ' ' << rest[2][i][0] <<
          endl;
      }
    } else {
      cout << 5 << endl;
      cout << rest[2][i][0] << ' ' << rest[2][i][1] << ' ' <<
        rest[3][i][0] << ' ' << rest[3][i][1] << ' ' << rest[3][i][2] <<
        endl;
      cout << rest[2][i][1] << ' ' << rest[2][i][0] << ' ' <<
        rest[3][i][1] << ' ' << rest[3][i][2] << ' ' << rest[3][i][0] <<
        endl;
    }
  }
    rb(i, tot[2], tot[3]) {
      if (i + 2 < tot[3]) {
        cout << 5 << endl;
        cout << 
          rest[3][i][0] << ' ' << rest[3][i][1] << ' ' << rest[3][i][2] <<
          ' ' << rest[3][i + 1][0] << ' ' << rest[3][i + 1][1] << 
          endl;
        cout <<
          rest[3][i][1] << ' ' << rest[3][i][2] << ' ' << rest[3][i][0] <<
          ' ' << rest[3][i + 1][1] << ' ' << rest[3][i + 1][0] << 
          endl;
        i += 2;
        cout << 5 << endl;
        cout << 
          rest[3][i][0] << ' ' << rest[3][i][1] << ' ' << rest[3][i][2] <<
          ' ' << rest[3][i - 1][0] << ' ' << rest[3][i - 1][2] << 
          endl;
        cout <<
          rest[3][i][1] << ' ' << rest[3][i][2] << ' ' << rest[3][i][0] <<
          ' ' << rest[3][i - 1][2] << ' ' << rest[3][i - 1][0] << 
          endl;
      } else {
        cout << 3 << endl;
        cout << 
          rest[3][i][0] << ' ' << rest[3][i][1] << ' ' << rest[3][i][2] <<
          endl;
        cout <<
          rest[3][i][1] << ' ' << rest[3][i][2] << ' ' << rest[3][i][0] <<
          endl;
      }
    }

    /*
    cout << "cycles" << endl;
  r(i, ncycle) {
    r(j, s(cycle[i])) {
      cout << cycle[i][j] + 1 << ' ';
    }
    cout << endl;
  }
  cout << endl;//*/
} 

