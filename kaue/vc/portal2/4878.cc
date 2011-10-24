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
    int t, n;
    cin >> t >> n;
    //ppn(n);
    int state = 0;
    int cnt;
    int add;
    bool isread;
    int nbytes;
    char cl, da;
    char scl[2000], sda[2000];
    ri {
      char a, b;
      cin >> a >> b;
      assert((a == '0' || a == '1') &&
          (b == '0' || b == '1'));
      scl[i] = a - '0';
      sda[i] = b - '0';
    }

    ri {
      //ppn(i);
      //cin >> cl >> da;
      cl = scl[i];
      da = sda[i];
      //ppn(state);
      //ppn(cl);
      //ppn(da);
      //pl;
      //cl -= '0';
      //da -= '0';
      if (state == 0) {
        if (da == 0 && cl == 1) {
          state++;
          cnt = 0;
          add = 0;
        }
      } else if (state == 1) {
        add *= 2;
        add += da;
        cnt++;
        //ppn(cnt);
        if (cnt == 7) {
          //printf("add => %X\n", add);
          state++;
        }
        i++;
      } else if (state == 2) {
        isread = da;
        //ppn(isread);
        i++;
        i++;
        state++;
      } else if (state == 3) {
        if (da) break;
        state++;
        nbytes = 0;
      } else if (state == 4) {
        //if (cl && da) {
          //state = 10;
          //break;
        //}
          //ppn(i);
          //ppn(n - i);
        if (i + 14 > n) {
          //ppn(i);
          //ppn(n - i);
          if (n - i == 4) {
            char ecl[] = "0111",
                 eda[] = "0011";
            bool found = false;
            r(j, 4) {
              //ppn(j);
              //ppn(ecl[j]);
              if (scl[i + j] != ecl[j] - '0' ||
                  sda[i + j] != eda[j] - '0') {
                found = true;
                ppn(found);
                break;
              }
            }
            if (!found) {
              state = 10;
              break;
            }
          } else {
            p("breaking\n");
            break;
          }
        }
        i += 16;
        nbytes++;
        state++;
        //if (nbytes == 2) {
          //string rest;
          //cin >> rest;
          //ppn(rest);
        //}
      } else if (state == 5) {
        if (da && cl) {
          //string rest;
          //cin >> rest;
          //ppn(rest);
          //break;
          i++;
          continue;
        }
        if (cl && !da) {
          state = 4;
        } else { // !cl
        //string rest;
        //cin >> rest;
        //ppn(rest);
          //cin >> cl >> da; i++;
          state = 6;
        }
      } else if (state == 6) {
        //string rest;
        //cin >> rest;
        //ppn(rest);
        if (cl && !da) {
          state = 4;
        } else {
          //cin >> cl >> da;  // what more?? i++;
        }
      }
    }
    //ppn(state);
    if (state == 10) {
      cout << t << " " << (isread ? "READ" : "WRITE")
        << " OF " << nbytes << " BYTES "
        << (isread ? "FROM" : "TO") << " SLAVE ";
      printf("%02X", add);
      cout << endl;
      //ppn(state);
      //ppn(nbytes);
    } else if (state == 4) {
      cout << t << " ERROR NO STOP BIT" << endl;
    } else if (state == 3 || state == 2) {
      cout << t << " ERROR NO ACK FROM SLAVE ";
      printf("%X", add);
      cout << endl;
    } else if (state == 5 || state == 6) {
      cout << t << " ERROR NO ACK FOR DATA" << endl;
    } else if (state == 0) {
      cout << t << " ERROR NO START BIT" << endl;
    }
  }
} 

