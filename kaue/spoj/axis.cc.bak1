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

pair<ld, ld> v[1000], w[1000], z[1000];
 
ld sqr(ld x) { return x * x; }

template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

int main() {
  int n;
  while (scanf("%d", &n) && n != -1) {
    ri {
      int a, b;
      scanf("%d%d", &a, &b);
      v[i] = make_pair((ld)a, (ld)b);
    }
    bool found = false;
    ri {
      rb(j, i + 1, n) {
        rb(k, j + 1, n) {
          ld area =
            v[i].first * (v[j].second - v[k].second) +
            v[j].first * (v[k].second - v[i].second) +
            v[k].first * (v[i].second - v[j].second);
          if (area != 0) {
            found = true;
            swap(v[i], v[0]);
            swap(v[j], v[1]);
            swap(v[k], v[2]);
            break;
          }
        }
        if (found) break;
      }
      if (found) break;
    }
    if (!found) {
      cout << 'Y' << endl;
      continue;
    }
    bool res = false;
    r(i, 3) {
      //ppn(i);
      rb(j, i, n) {
        //ppn(j);
        //ppn(v[i]);
        //ppn(v[j]);
        pair<ld, ld> middle = make_pair(
            (v[i].first + v[j].first) / 2,
            (v[i].second + v[j].second) / 2);
        //ppn(middle);
        rk {
          z[k].first = v[k].first - middle.first;
          z[k].second = v[k].second - middle.second;
          //ppn(k);
          //ppn(v[k]);
          //ppn(z[k]);
        }
        ld hip = sqrt(sqr(v[i].first - v[j].first) +
                      sqr(v[i].second - v[j].second));
        //ppn(hip);
        ld sinv = (v[j].second - v[i].second) / hip;
        //ppn(sinv);
        ld cosv = (v[j].first - v[i].first) / hip;
        //ppn(cosv);
        int cntleft = 0, cntright = 0;
        rk {
          w[k].first  = cosv * z[k].first - sinv * z[k].second;
          w[k].second = sinv * z[k].first + cosv * z[k].second;
          if (w[k].first < 0) cntleft++;
          if (w[k].first > 0) cntright++;
          //ppn(k);
          //ppn(z[k]);
          //ppn(w[k]);
        }

        //ppn(cntleft);
        //ppn(cntright);
        if (cntleft != cntright) continue;

        sort(w, w + n);
        //pv(w);
        //pl;
        bool found = false;
        rk {
          //ppn(k);
          //ppn(w[k]);
          int begin = 0, end = n - 1;
          bool ok = false;
          while (begin <= end) {
            //ppn(begin);
            //ppn(end);
            int cur = begin + (end - begin) / 2;
            //ppn(cur);
            //ppn(w[cur]);
            if (w[cur].first == -w[k].first) {
              if (w[cur].second == w[k].second) {
                ok = true;
                break;
              } else if(w[cur].second < w[k].second) {
                begin = cur + 1;
              } else {
                end = cur - 1;
              }
            } else if(w[cur].first < -w[k].first) {
              begin = cur + 1;
            } else {
              end = cur - 1;
            }
          }
          //ppn(ok);
          //pl;
          if (!ok) {
            found = true;
            break;
          }
        }
        if (!found) {
          res = true;
          break;
        }
      }
      if (res) break;
    }
    if (res) cout << "Y" << endl;
    else cout << "N" << endl;
  }
} 

