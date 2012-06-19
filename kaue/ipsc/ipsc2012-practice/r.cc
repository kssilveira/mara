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
 
typedef long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

int MAX = 44444;

ull gcd(ull a, ull b) {
  if (b == 0) return a;
  return gcd(b, a % b);
  //while (b != 0) {
    //ull t = a;
    //a = b;
    //b = t % b;
  //}
  //return a;
}

ull gcd4(ull a, ull b, ull c, ull d) {
  return gcd(gcd(gcd(a, b), c), d);
}
 
int main(int argc, char**argv) {
  if (argc == 2) {
    sscanf(argv[1], "%d", &MAX);
  }

  /*
  for (int i = 0; i <= MAX; i++) {
    is_sq[i * i] = true;
    sq.push_back(i * i);
  }

  for (ull i = 0; i <= MAX; i++) {
    for (ull j = 0; j <= MAX; j++) {
      ull v = i * i + j * j;
      for (int k = 0; k <= MAX; k++) {
        if (is_sq[sq[k] - v]) {
          cout << i << ' ' << j << ' ' << k << ' ' << '
        }
      }
    }
  }//*/

  /*
  ull res = 0;
  for (ull i = 0; i <= MAX; i++) {
    for (ull j = 0; j <= MAX; j++) {
      for (ull k = 0; k <= MAX; k++) {
        ull v = i * i + j * j + k * k;
        ull sq = sqrt(v);
        if (sq > MAX) {
          break;
        }
        if (sq * sq == v) {
          res++;
        }
      }
    }
  }
  cout << "res: " << res << endl;//*/

  
  typedef set<pair<int, pair<int, int> > > Set;
  Set res;
  for (ull m = 0; m * m <= MAX; m++) {
    fprintf(stderr, "%f\n", sqrt(MAX) - m); fflush(stderr);
    ull endn = MAX - m * m;
    for (ull n = 0; n * n <= endn; n++) {
      ull endp = endn - n * n;
      for (ull p = 0; p * p <= endp; p++) {
        ull endq = endp - p * p;
        for (ull q = 0; q * q <= endq; q++) {
          if ((m + n + p + q) % 2 != 1) continue;
          if (gcd4(m, n, p, q) != 1) continue;
          //cout << m << ' ' << n << ' ' << p << ' ' << q << endl;
          ull a = (((m * m + n * n) - p * p) - q * q);
          ull b = 2 * (m * q + n * p);
          ull c = 2 * (n * q - m * p);
          ull d = m * m + n * n + p * p + q * q;
          if (gcd4(a, b, c, c) != 1) continue;
          //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
          ull v[3] = {abs(a), abs(b), abs(c)};
          sort(v, v + 3);
          if (v[0] == 0 && v[1] == 0 && v[2] != 1) continue;
          res.insert(make_pair(v[0], make_pair(v[1], v[2])));
        }
      }
    }
  }

  //cout << "res.size(): " << res.size() << endl;


  ull cnt[45000] = {0};
  cnt[0] = 1;
  for (Set::iterator it = res.begin(); it != res.end(); it++) {
    ull a = it->first, b = it->second.first, c = it->second.second;
    ull cur = 1;
    if (a != 0) cur *= 2;
    if (b != 0) cur *= 2;
    if (c != 0) cur *= 2;
    if (a == b && b == c) {}
    else if(a == b || b == c) { cur *= 3; }
    else { cur *= 6; }
    ull d = sqrt(a * a + b * b + c * c);
    assert(d <= MAX);
    cnt[d] += cur;
    //if (d == 15) {
      //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << cur << endl;
    //}
  }

  /*
  for (int i = 1; i <= MAX; i++) {
    cnt[i] += cnt[i - 1];
  }//*/

  //for (int i = 0; i <= MAX; i++) {
    //cout << cnt[i] << ' ';
  //}
  //cout << endl;

  ull precalc[45000] = {0};
  precalc[0] = 1;
  for (ull r = 1; r <= MAX; r++) {
    ull total = 0;
    for (ull i = 1; i * i <= r; i++) {
      if (r % i != 0) continue;
      total += cnt[i];
      ull other = r / i;
      if (other != i) {
        total += cnt[other];
      }
    }
    precalc[r] = total;
  }

  //for (int i = 0; i <= MAX; i++) {
    //cout << precalc[i] << ' ';
  //}
  //cout << endl;

  ull theres[45000] = {0};
  theres[0] = precalc[0];
  for (ull i = 1; i <= MAX; i++) {
    theres[i] = theres[i - 1] + precalc[i];
  }

  //for (int i = 0; i <= MAX; i++) {
    //cout << i + 1 << ": " << theres[i] << endl;
  //}
  //cout << endl;

  //*
  int T;
  cin >> T;
  while (T--) {
    ull r;
    cin >> r;
    cout << theres[r - 1] << endl;
    /*
    ull total = 0;
    for (ull i = 1; i * i <= r; i++) {
      total += cnt[i];
      ull other = r / i;
      if (other != i) {
        total += cnt[other];
      }
    }
    cout << total << endl;//*/
  }
  //*/
} 

