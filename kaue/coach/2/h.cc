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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int order[2][1010] = {{0}};
    set<int> val[2];
    int stock = -1;
    int bid_price = -2, ask_price = -1;
    ri {
      char what[10];
      int x, y;
      scanf("%s %d shares at %d", what, &x, &y);
      int type = 0;
      if (!strcmp(what, "buy")) type = 1;
      //ppn(what); ppn(type); ppn(x); ppn(y);
      order[type][y] += x;
      val[type].insert(y);
      /*
      int cur = min(order[0][y], order[1][y]);
      if (cur > 0) {
        stock = y;
        r(i, 2) {
          order[i][y] -= cur;
          if (order[i][y] == 0) {
            val[i].erase(y);
          }
        }
      }//*/
      while (1) {
        if (!val[0].empty()) {
          ask_price = *val[0].begin();
        } else {
          ask_price = INT_MAX;
        }
        if (!val[1].empty()) {
          bid_price = *val[1].rbegin();
        } else {
          bid_price = -2;
        }

        //ppn(ask_price);
        //ppn(bid_price);
        
        int what[2] = {ask_price, bid_price};
        if(bid_price >= ask_price) {
          int cur = min(order[0][what[0]], order[1][what[1]]);
          //ppn(cur);
          stock = ask_price;
          r(i, 2) {
            order[i][what[i]] -= cur;
            if (order[i][what[i]] == 0) {
              val[i].erase(what[i]);
            }
          }
        } else break;
      }

      if (!val[0].empty()) {
        cout << *val[0].begin();
        ask_price = *val[0].begin();
      } else {
        cout << "-";
      }
      cout << " ";
      if (!val[1].empty()) {
        cout << *val[1].rbegin();
        bid_price = *val[1].rbegin();
      } else {
        cout << "-";
      }
      if (stock != -1) {
        cout << " " << stock;
      } else {
        cout << " -";
      }
      cout << endl;
    }
  }
} 

