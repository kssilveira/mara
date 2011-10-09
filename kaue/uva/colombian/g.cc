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

int main() {
  int l, g;
  while (cin >> l >> g && l > 0) {
    vector<pair<int, int> > val;
    r(i, g) {
      int x, r;
      cin >> x >> r;
      //val.push_back(make_pair(min(l, x + r), max(0, x - r)));
      val.push_back(make_pair(max(0, x - r), min(l, x + r)));
    }
    sort(all(val));

    /*
    r(i, s(val)) {
      cout << '(' << val[i].first << "," << val[i].second << ") ";
    }
    cout << endl;//*/

    if (val[0].first != 0) {
      cout << -1 << endl;
      continue;
    }

    int beg = val[0].first, end = val[0].second;
    int i = 0;
    bool valid = true;
    int res = 0;
    while (i < s(val)) {
      //ppn(i);
      //ppn(beg);
      //ppn(end);
      //ppn(res);
      int j = i + 1; 
      while (val[j].first == beg && j < s(val)) {
        res++;
        end = val[j].second;
        j++;
      }

      while (j < s(val) && val[j].second <= end) {
        res++;
        j++;
      }

      if (j == s(val)) break;

      if (val[j].first > end) {
        valid = false;
        break;
      }

      int nextbegin = val[j].first;
      int nextend = val[j].second;
      int k = j + 1;
      while (k < s(val) && val[k].first <= end) {
        if (val[k].second > nextend) {
          nextend = val[k].second;
          nextbegin = val[k].first;
        }
        res++;
        k++;
      }

      beg = nextbegin;
      end = nextend;
      i = k - 1;
    }

    if (!valid || end != l) {
      cout << -1 << endl;
    } else {
      cout << res << endl;
    }
  }
} 

