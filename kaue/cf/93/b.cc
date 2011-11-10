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

const ull BASE = 5347;
ull pot[1000010] = {0};
ull hashbegin[1000010] = {0};
ull hashend[1000010] = {0};
 
int main() {
  string s;
  cin >> s;
  int n = s(s);
  //ppn(n);
  ll low = 1, high = n - 2;
  pot[0] = 1;
  rb(i, 1, n) {
    pot[i] = pot[i - 1] * BASE;
  }
  int res = 0;
  bool solved = false;
  hashbegin[0] = s[0] - 'a' + 1;
  rb(i, 1, n) {
    hashbegin[i] = hashbegin[i - 1] * BASE + s[i] - 'a' + 1;
  }
  hashend[n - 1] = s[n - 1] - 'a' + 1;
  for (int i = n - 2; i >= 0; i--) {
    hashend[i] = hashend[i + 1] + (s[i] - 'a' + 1) * pot[n - 1 - i];
  }
  for (ll mid = high; mid >= low && !solved; mid--) {
    //ll mid = low + (high - low) / 2;
    //mid = 2;
    //ppn(mid);
    ull hasha = hashbegin[mid - 1];
    //r(i, mid) {
      //hasha *= BASE;
      //hasha += s[i] - 'a' + 1;
    //}
    //ppn(hasha);
    //assert(hasha == hashbegin[mid - 1]);
    ull hashb = hashend[n - mid];
    //rb(i, n - mid, n) {
      //hashb *= BASE;
      //hashb += s[i] - 'a' + 1;
    //}
    //assert(hashb == hashend[n - mid]);
    //ppn(hashb);
    //ppn(hashbegin[n - 1]);
    //ppn(n - 1);
    //ppn(n - mid - 1);
    //ppn(hashbegin[n - mid - 1]);
    //ppn(hashbegin[n - 1] - hashbegin[n - mid - 1]);
    //assert(hashb ==
        //(hashbegin[n - 1] / pot[n - mid] -
         //hashbegin[n - mid - 1] / pot[n - mid]));
    if (hasha != hashb) {
      //high = mid - 1;
      continue;
    }
    //cout << "HERE!";
    ull hashc = hasha;
    bool found = false;
    rb(i, mid, n - 1) {
      hashc -= pot[mid - 1] * (s[i - mid] - 'a' + 1);
      hashc *= BASE;
      hashc += s[i] - 'a' + 1;
      if (hashc == hasha) {
        found = true;
        solved = true;
        res = mid;
        low = mid + 1;
        break;
        //ppn(i);
      }
      //ppn(hashc);
    }
    if (!found) {
      high = mid - 1;
    }
  }
  if (solved) {
    cout << s.substr(0, res) << endl;
  } else {
    cout << "Just a legend" << endl;
  }
} 

