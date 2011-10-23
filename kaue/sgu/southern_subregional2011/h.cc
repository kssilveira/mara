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

ull gcd(ull x, ull y) {
  while (y) {
    ull t = x;
    x = y;
    y = t % y;
  }
  return x;
}

int main() {
  int T;
  scanf("%d", &T);
  r(t, T) {
    char s[20];
    scanf("%s", s);
    bool found[300] = {0};
    int ind[300] = {0};
    int n = strlen(s);
    int cnt = 0;
    ri {
      if (!found[s[i]]) {
        found[s[i]] = true;
        ind[s[i]] = cnt;
        cnt++;
      }
    }
    //ppn(cnt);
    int perm[10];
    r(i, 10) {
      perm[i] = i;
    }
    swap(perm[0], perm[1]);

    ull res = 0;
    do {
      /*/
      r(i, cnt) {
        cout << perm[i] << ' ';
      }
      cout << endl;//*/

      if (perm[0] != 1) break;

      if (res == 1) break;

      //if (perm[ind[s[0]]] != 0) {
        ull val = 0;
        ri {
          val *= 10;
          val += perm[ind[s[i]]];
        }
        //ppn(val);
        if (res == 0) res = val;
        res = gcd(res, val);
        reverse(perm + cnt, perm + 10);
      //} else {
        //reverse(perm + 1, perm + 10);
      //}

    } while(next_permutation(perm, perm + 10));
    //ppn(res);

    vector<ull> res_div;
    res_div.push_back(1);
    {
      int i = 2;
      int cnt = 0;
      while (res % i == 0) {
        cnt++;
        res /= i;
      }
      ull what = 1, who = i;
      vector<ull> to_add;
      for (int i = 0; i < cnt; i++) {
        what *= who;
        for (vector<ull>::iterator it = res_div.begin();
            it != res_div.end();
            it++) {
          to_add.push_back(*it * what);
        }
      }
      for (vector<ull>::iterator it = to_add.begin();
          it != to_add.end();
          it++) {
        res_div.push_back(*it);
      }
    }
    for (ull i = 3; i * i <= res; i += 2) {
      int cnt = 0;
      while (res % i == 0) {
        cnt++;
        res /= i;
      }
      ull what = 1, who = i;
      vector<ull> to_add;
      for (int i = 0; i < cnt; i++) {
        what *= who;
        for (vector<ull>::iterator it = res_div.begin();
            it != res_div.end();
            it++) {
          to_add.push_back(*it * what);
        }
      }
      for (vector<ull>::iterator it = to_add.begin();
          it != to_add.end();
          it++) {
        res_div.push_back(*it);
      }
    }

    if (res > 1) {
      int what = res;
      int cnt = 1;
      for (int i = 0; i < cnt; i++) {
        vector<ull> to_add;
        for (vector<ull>::iterator it = res_div.begin();
            it != res_div.end();
            it++) {
          to_add.push_back(*it * what);
        }
        for (vector<ull>::iterator it = to_add.begin();
            it != to_add.end();
            it++) {
          res_div.push_back(*it);
        }
      }
    }

    cout << "Case " << t + 1 << ":";
    sort(all(res_div));
    //vector<ull>::iterator end = unique(all(res_div));
    vector<ull>::iterator end = res_div.end();
    for (vector<ull>::iterator it = res_div.begin();
        //it != res_div.end();
        it != end;
        it++) {
      cout << " ";
      cout << *it;
    }
    cout << endl;
  }
} 

