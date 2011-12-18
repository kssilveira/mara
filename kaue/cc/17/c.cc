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

ld base;
ld baseb;

bool gone[110][110][10];
ld memo[110][110][10];

int VA, VB, MA;

ld solve(int va, int sa, int vb, int sb, int ma) {
  //printf("solve(%d, %d, %d)\n", va, vb, ma);
  if (va <= 0 && vb <= 0) return max(base,
      memo[VA][VB][MA] / ((sa + 1) * (sb + 1) - 1));
  if (va <= 0) return 0;
  if (vb <= 0) return baseb;

  ld& res = memo[va][vb][ma];

  if (gone[va][vb][ma]) {
    return res;
  }

  gone[va][vb][ma] = true;

  res = 0.0;

  ld oldsa = sa, oldsb = sb;
  sa = min(sa, vb);
  sb = min(sb, va);

  rb(s, 0, sa + 1) {
    rb(t, 0, sb + 1) {
      if (s == 0 && t == 0) continue;
      res += solve(va - t, oldsa, vb - s, oldsb, ma);
    }
  }

  if (sb < va) {
    res += (oldsa - sa) * (sb + 1) * baseb;
  } else {
    res += (oldsa - sa) * (sb) * baseb;
    if (sa == vb) {
      res += ((oldsa - sa + 1) * (oldsb - sb + 1) - 1) * base;
    }
  }
  //res += (oldsb - sb) * (sa - 1) * 0;

  res /= ((oldsa + 1) * (oldsb + 1) - 1);

  if (ma > 0) {
    res = max(res, solve((va + 1) / 2, oldsa, (vb + 1) / 2, oldsb, ma - 1));
  }

  return res;
}
 
int main() {
  int va, sa, vb, sb, ma;
  cin >> va >> vb >> sa >> sb >> ma;
  VA = va;
  VB = vb;
  MA = ma;
  memo[VA][VB][MA] = 0;
  //*
  ld low = 0, high = 1;
  ld res = 0;
  baseb = 1;
  while (high - low > 1e-7) {
    base = low + (high - low) / 2;
    ppn(low); ppn(high); ppn(base);
    memset(gone, 0, sizeof(gone));
    res = solve(va, sa, vb, sb, ma);
    if (res < base) {
      high = base;
    } else {
      low = base;
    }
    ppn(res);
  }//*/
  /*
  base = 0;
  baseb = 1;
  memset(gone, 0, sizeof(gone));
  ld resa = solve(va, sa, vb, sb, ma);
  base = 1;
  baseb = 0;
  memset(gone, 0, sizeof(gone));
  ld resb = solve(va, sa, vb, sb, ma);
  ppn(resa);
  ppn(resb);
  //ld resc = resb - resa;
  ld resc = resb;
  ld res = resa / (1 - resc);//*/
  /*
  base = 1;
  baseb = 1;
  ld res = 0;
  while (fabs(base - res) >= 1e-7) {
    base = res;
    memset(gone, 0, sizeof(gone));
    res = solve(va, sa, vb, sb, ma);
    ppn(res);
  }//*/
  cout << fixed << setprecision(10) << res << endl;
} 

