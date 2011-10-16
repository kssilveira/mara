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

ld get_tan(ld d1, ld h1, ld d2, ld h2) {
  return (h2 - h1) / (ld)(d2 - d1);
}

ld sqr(ld x) {
  return x * x;
}

ld distance(ld d1, ld h1, ld d2, ld h2) {
  return sqrt(sqr(d1 - d2) + sqr(h1 - h2));
}
 
int main() {
  int n;
  while (cin >> n && n) {
    ld timedown = 0;
    ld lastd, lasth;
    vector<pair<ld, ld> > val;
    ri {
      ld dd, hh;
      cin >> dd >> hh;
      hh /= 1000; // meter to km
      //dd *= 1000;
      if (i > 0) {
        if (hh > lasth) { // uphill
          val.push_back(
              make_pair(get_tan(lastd, lasth, dd, hh) * 1,
                dd - lastd));
        } else { // downhill
          ld dist = dd - lastd; // distance(lastd, lasth, dd, hh);
          timedown += dist; // 1km / minute
        }
      }
      lastd = dd;
      lasth = hh;
    }
    //ppn(timedown);
    sort(all(val));
    /*
    r(i, s(val)) {
      cout << '(' << val[i].first << "," << val[i].second << ')' << ' ';
    }
    cout << endl;//*/
    int c;
    cin >> c;
    r(i, c) {
      ld M;
      int h, m, s;
      cin >> M >> h >> m >> s;
      ld total = h * 60 + m + s / (ld) 60;
      //ppn(M);
      //ppn(total);
      total -= timedown;
      //ppn(total);
      r(j, s(val)) {
        //r(l, val[j].second) {
        int quilo = min((int) (M / val[j].first), (int) val[j].second);
        //ppn(quilo);
          //if () {  // x = 1
            M -= quilo * val[j].first;
            //total -= val[j].second; // 1minute / km
            total -= quilo; // 1minute / km
          //} else { // x < 1
        if (quilo < val[j].second) {
            ld x = M / (ld) val[j].first;
            ld t = 6 - 5 * x;
            //total -= t * val[j].second; // t minutes / km
            total -= t; // t minutes / km
            M = 0;
            ld rest = val[j].second - quilo - 1;
            if (rest > 0) {
              total -= 6 * rest;
            }
          }
        //}
      }
      //ppn(M);
      //ppn(total);
      if (total >= 0) {
        cout << "PASS" << endl;
      } else {
        cout << "SHOOT" << endl;
      }
    }
  }
} 

