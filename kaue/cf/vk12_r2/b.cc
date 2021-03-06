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

const int MAX = 100010;

#define EPS 1e-10
 
int main() {
  int n, k, h;
  cin >> n >> k >> h;
  int m[MAX], v[MAX], res[MAX], ans[MAX];
  ri {
    cin >> m[i];
  }
  ri {
    cin >> v[i];
  }
  vector<pair<int, pair<ll, int> > > vet;
  ri {
    vet.push_back(make_pair(m[i], make_pair(v[i], i)));
  }
  sort(all(vet));
  double begin = 0, end = 1000000010;
  int ITER = 0;
  while (ITER < 200) {
    ITER++;
    double cur = (begin + end) / 2;
    //ppn(cur);
    ll cnt = 1;
    ri {
      //ppn(i); ppn(vet[i].second.first); ppn(cnt * h);
      //ppn(vet[i].second.first * cur);
      if (vet[i].second.first * cur >= cnt * h) {
        //ppn(cnt);
        res[cnt - 1] = vet[i].second.second;
        cnt++;
        if (cnt > k) {
          break;
        }
      }
    }
    if (cnt > k) {
      end = cur;
      r(i, k) {
        ans[i] = res[i];
      }
    } else {
      begin = cur;
    }
  }
  {
    r(i, k) {
        if (i > 0) {
          cout << ' ';
        }
        cout << ans[i] + 1;
    }
  }
  cout << endl;
} 

