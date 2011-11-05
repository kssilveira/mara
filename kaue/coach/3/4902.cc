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
  int n;
  while (cin >> n && n) {
    bool tab[10][40][40] = {{{0}}},
        ntab[10][40][40] = {{{0}}};
    string line;
    getline(cin, line);
    r(f, 6) {
      ri {
        getline(cin, line);
        //ppn(line);
        rj {
          //char c;
          //cin >> c;
          tab[f][i][j] = line[j] != 'X';
        }
      }
    }
    /*
    r(f, 6) {
      ppn(f);
      ri {
        rj {
          cout << tab[f][i][j] << ' ';
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;//*/
    ri {
      rj {
        ntab[0][i][j] = tab[0][n - 1 - i][n - 1 - j];
        ntab[1][i][j] = tab[1][n - 1 - i][j];
        ntab[2][i][j] = tab[2][n - 1 - i][j];
        ntab[3][i][j] = tab[3][n - 1 - i][n - 1 - j];
        ntab[4][i][j] = tab[4][n - 1 - i][n - 1 - j];
        ntab[5][i][j] = tab[5][i][n - 1 - j];
      }
    }
    /*
    r(f, 6) {
      ppn(f);
      ri {
        rj {
          cout << ntab[f][i][j] << ' ';
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;//*/
    ri {
      rj {
        tab[0][i][j] = ntab[0][i][j] && ntab[2][i][j];
        tab[1][i][j] = ntab[1][i][j] && ntab[3][i][j];
        tab[2][i][j] = ntab[4][i][j] && ntab[5][i][j];
      }
    }
    /*
    r(f, 3) {
      ppn(f);
      ri {
        rj {
          cout << tab[f][i][j] << ' ';
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;//*/
    queue<pair<pair<pair<int, int>, pair<int, int> >, string > > q;
    q.push(make_pair(make_pair(make_pair(0, 1), make_pair(1, 1)), ""));
    bool gone[40][40][40] = {{{false}}};
    int dx[] = {+0, +0, +0, +0, +1, -1},
        dy[] = {+0, +0, +1, -1, +0, +0},
        dz[] = {-1, +1, +0, +0, +0, +0};
    char ch[] = "FBLRUD";
    while (!q.empty()) {
      int dist = q.front().first.first.first,
          x = q.front().first.first.second,
          y = q.front().first.second.first,
          z = q.front().first.second.second;
      string res = q.front().second;
      q.pop();
      //printf("%d: %d %d %d (%s)\n", dist, x, y, z, res.c_str());
      if (x == n - 2 && y == n - 2 && z == n - 2) {
        cout << res << endl;
        break;
      }
      gone[x][y][z] = true;
      r(d, 6) {
        int nx = x + dx[d],
            ny = y + dy[d],
            nz = z + dz[d];
        if (nx < 0 || nx >= n ||
            ny < 0 || ny >= n ||
            nz < 0 || nz >= n) continue;
        if (!tab[0][nx][ny] || !tab[1][nx][nz] || !tab[2][nz][ny])
          continue;
        if (gone[nx][ny][nz]) continue;
        gone[nx][ny][nz] = true;
        q.push(make_pair(make_pair(make_pair(dist + 1, nx),
              make_pair(ny, nz)), res + ch[d]));
      }
    }
  }
} 

