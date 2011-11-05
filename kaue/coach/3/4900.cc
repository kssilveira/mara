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

ld sqr(ld x) { return x * x; }

ld dist(ld x1, ld y1, ld x2, ld y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

const ld EPS = 0.01;
const ld toRad180 = atan(1) * 4;

ld getang(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
  ld dot = (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1);
  dot = dot / (dist(x1, y1, x2, y2) * dist(x1, y1, x3, y3));
  return acos(dot);
}
 
int main() {
  int n;
  int Case = 0;
  bool second = false;
  //ppn(toRad180);
  while (cin >> n && n) {
    if (second) cout << endl;
    second = true;
    Case++;
    ld hole[30][3][2];
    ld holeside[30][3];
    ld tri[30][3][2];
    ld ang[30][3];
    ri {
      r(j, 3) {
        cin >> hole[i][j][0] >> hole[i][j][1];
      }
      r(j, 3) {
        holeside[i][j] = dist(hole[i][j][0], hole[i][j][1],
            hole[i][(j + 1) % 3][0], hole[i][(j + 1) % 3][1]);
      }
      sort(holeside[i], holeside[i] + 3);
    }
    r(i, 2 * n) {
      r(j, 3) {
        cin >> tri[i][j][0] >> tri[i][j][1];
      }
      r(j, 3) {
        ang[i][j] = getang(tri[i][j][0], tri[i][j][1],
            tri[i][(j + 1) % 3][0], tri[i][(j + 1) % 3][1],
            tri[i][(j + 2) % 3][0], tri[i][(j + 2) % 3][1]);
      }
    }
    vector<pair<int, int> > res;
    res.resize(n);
    bool used[30] = {0};
    r(i, 2 * n) {
      bool found = false;
      r(si, 3) {
        if (found) break;
        ld side = dist(tri[i][si][0], tri[i][si][1],
            tri[i][(si + 1) % 3][0], tri[i][(si + 1) % 3][1]);
        r(j, 2 * n) {
          if (i == j) continue;
          int perm[] = {0, 1, 2};
          do {
            int a = perm[0], b = perm[1], c = perm[2];
            ld sidej = dist(tri[j][a][0], tri[j][a][1],
                tri[j][b][0], tri[j][b][1]);
            if (fabs(side - sidej) >= EPS) continue;
            ld sum1 = ang[i][si] + ang[j][a];
            ld sum2 = ang[i][(si + 1) % 3] + ang[j][b];
            ld triside[3];
            if (fabs(sum1 - toRad180) < EPS) {
              triside[0] = dist(
                  tri[i][(si + 1) % 3][0], tri[i][(si + 1) % 3][1],
                  tri[i][(si + 2) % 3][0], tri[i][(si + 2) % 3][1]);
              triside[1] = dist(
                  tri[i][(si + 2) % 3][0], tri[i][(si + 2) % 3][1],
                  tri[i][(si + 3) % 3][0], tri[i][(si + 3) % 3][1]) +
                dist( // a c
                  tri[j][a][0], tri[j][a][1],
                  tri[j][c][0], tri[j][c][1]);
              triside[2] = dist( // b c
                  tri[j][b][0], tri[j][b][1],
                  tri[j][c][0], tri[j][c][1]);
            } else if(fabs(sum2 - toRad180) < EPS) {
              triside[0] = dist(
                  tri[i][(si + 1) % 3][0], tri[i][(si + 1) % 3][1],
                  tri[i][(si + 2) % 3][0], tri[i][(si + 2) % 3][1]) +
              dist( // b c
                  tri[j][b][0], tri[j][b][1],
                  tri[j][c][0], tri[j][c][1]);
              triside[1] = dist(
                  tri[i][(si + 2) % 3][0], tri[i][(si + 2) % 3][1],
                  tri[i][(si + 3) % 3][0], tri[i][(si + 3) % 3][1]);
              triside[2] = 
                dist( // a c
                  tri[j][a][0], tri[j][a][1],
                  tri[j][c][0], tri[j][c][1]);
            } else {
              continue;
            }
            sort(triside, triside + 3);
            r(k, n) {
              if (used[k]) continue;
              bool wrong = false;
              r(l, 3) {
                if (fabs(holeside[k][l] - triside[l]) < EPS) {
                } else {
                  wrong = true;
                  break;
                }
              }
              if (!wrong) {
                found = true;
                res[k] = make_pair(i, j);
                used[k] = true;
                break;
              }
            }
            if (found) break;
          } while(next_permutation(perm, perm + 3));

          if (found) break;
          /*
          r(sj, 3) {
            ld sidej = dist(tri[j][sj][0], tri[j][sj][1],
                tri[j][(sj + 1) % 3][0], tri[j][(sj + 1) % 3][1]);
            if (fabs(side - sidej > EPS)) continue;
            ld sum = 
          }//*/
        }
      }
    }
    cout << "Case " << Case << ":" << endl;
    r(i, n) {
      cout << "Hole " << i + 1 << ": ";
      cout << res[i].first + 1 << ", " << res[i].second + 1 << endl;
    }
  }
} 

