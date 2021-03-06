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

pair<ld, ld> v[1000];
 
ld sqr(ld x) { return x * x; }
typedef pair<ld, ld> Point;

template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

const ld EPS = 1e-9;

int main() {
  int n;
  while (scanf("%d", &n) && n != -1) {
    set<pair<int, int> > pt;
    ri {
      int a, b;
      scanf("%d%d", &a, &b);
      pt.insert(make_pair(a, b));
      v[i] = make_pair((ld)a, (ld)b);
    }
    bool res = false, last = false;
    r(i, 3) {
      if (last) break;
      //ppn(i);
      rb(j, i + 1, n) {
        if (last) break;
        if (i == 2) {
          last = true;
          i = 0;
          j = 1;
        }
        //pn("\n\n####");
        //ppn(j);
        //ppn(v[i]);
        //ppn(v[j]);
        pair<ld, ld> middle = make_pair(
            (v[i].first + v[j].first) / 2,
            (v[i].second + v[j].second) / 2);
        //ppn(middle);
        ld hip = sqrt(sqr(v[i].first - v[j].first) +
                      sqr(v[i].second - v[j].second));
        //ppn(hip);
        ld sinv = +(v[j].second - v[i].second) / hip;
        ld cosv = -(v[j].first - v[i].first) / hip; // minus here??
        if (last) {
          ld t = sinv;
          sinv = -cosv;
          cosv = t;
        }
        //ppn(sinv);
        //ppn(cosv);
        bool ok = true;
        rk {
          //pl;
          //ppn(k);
          //ppn(v[k]);
          Point translated(
              v[k].first - middle.first,
              v[k].second - middle.second);
          //ppn(translated);
          Point rotated(
              cosv * translated.first - sinv * translated.second,
              sinv * translated.first + cosv * translated.second);
          //ppn(rotated);
          Point symmetric(-rotated.first, rotated.second);
          //ppn(symmetric);
          Point sym_rot(
              cosv * symmetric.first + sinv * symmetric.second,
            - sinv * symmetric.first + cosv * symmetric.second);
          //ppn(sym_rot);
          Point sym_rot_trans(
              sym_rot.first + middle.first,
              sym_rot.second + middle.second);
          //ppn(sym_rot_trans);
          pair<int, int> pint(
              round(sym_rot_trans.first + EPS),
              round(sym_rot_trans.second + EPS));
          //ppn(pint);

          if (fabs(sym_rot_trans.first - pint.first) > EPS ||
              fabs(sym_rot_trans.second - pint.second) > EPS ||
              pt.find(pint) == pt.end()) {
            ok = false;
            break;
          }
        }
        if (ok) {
          res = true;
          //ppn(i); ppn(v[i]); ppn(j); ppn(v[j]);
          break;
        }
      }
      if (res) break;
    }
    printf("%s\n", res ? "Y" : "N");
  }
} 

