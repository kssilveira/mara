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
 
int tab[4][4];
string res;
const int n = 4;
const int dx[] = {-1, +0, +1, +0},
          dy[] = {+0, +1, +0, -1};
const char ch[] = "URDL";

const ull BASE = 5347;
const ull MOD = ull(1e9 + 7);
map<ull, bool> gone;
int pi[16], pinv[16];

ull rank(ull n) {
  if (n == 1) return 0;
  ull s = pi[n - 1];
  swap(pi[n - 1], pi[pinv[n - 1]]);
  swap(pinv[s], pinv[n - 1]);
  return s + n * rank(n - 1);
}

ull nmax;
bool solve(int cx, int cy) {
  //printf("solve(%d, %d, %d)\n", res.length(), cx, cy);
  if (res.length() > nmax) return false;
  ull hash = 0;
  /*
  ri {
    rj {
      hash *= BASE;
      hash %= MOD;
      hash += tab[i][j];
      hash %= MOD;
    }
  }//*/
  ri {
    rj {
      pi[i * n + j] = tab[i][j] - 1;
    }
  }
  r(i, 16) {
    pinv[pi[i]] = i;
  }
  /*
  r(i, 16) {
    cout << pi[i] << ' ';
  }
  cout << endl;
  r(i, 16) {
    cout << pinv[i] << ' ';
  }
  cout << endl;//*/

  hash = rank(16);
  //ppn(hash);
  if (gone.find(hash) != gone.end()) {
    //ppn(hash);
    //cout << "!";
    //return false;
  }
  gone[hash] = true;
  bool found = false;
  ri {
    rj {
      if (tab[i][j] != i * n + j + 1) {
        found = true;
        break;
      }
    }
    if (found) break;
  }
  if (!found) {
    return true;
  }
  ull dist = 0;
  ri {
    rj {
      if (tab[i][j] == 16) continue;
      int v = tab[i][j];
      int x = (v - 1) / n,
          y = (v - 1) % n;
      dist += abs(i - x) + abs(j - y);
    }
  }
  //ppn(dist);
  if (dist + res.length() > nmax) {
    //ppn(dist);
    //cout << "?";
    return false;
  }
  r(d, 4) {
    if (res.length() < 38) {
      //cout << res << endl;
    }
    int nx = cx + dx[d],
        ny = cy + dy[d];
    if (nx < 0 || nx >= 4 ||
        ny < 0 || ny >= 4) continue;
    swap(tab[cx][cy], tab[nx][ny]);
    res += ch[d];
    if (solve(nx, ny)) {
      return true;
    }
    res.resize(res.length() - 1);
    swap(tab[cx][cy], tab[nx][ny]);
  }
  return false;
}


int main() {
#if 0
  int perm[] = {0, 1, 2, 3};
  do {
    ull hash = 0;
    /*
    ri {
      rj {
        hash *= BASE;
        hash %= MOD;
        hash += tab[i][j];
        hash %= MOD;
      }
    }//*/
    r(i, 4) {
      pi[i] = perm[i];
    }
    r(i, 4) {
      pinv[pi[i]] = i;
    }
    r(i, 4) {
      cout << pi[i] << ' ';
    }
    cout << endl;
    r(i, 4) {
      cout << pinv[i] << ' ';
    }
    cout << endl;

    hash = rank(4);

    ppn(hash);

  } while (next_permutation(perm, perm + 4));
#endif
  int T;
  cin >> T;
  while (T--) {
    int bx, by;
    ri {
      rj {
        cin >> tab[i][j];
        if (tab[i][j] == 0) {
          bx = i;
          by = j;
          tab[i][j] = 16;
        }
      }
    }
    //ppn(bx); ppn(by);
    bool solved = false;
    r(i, 51) {
      res = "";
      gone.clear();
      nmax = i;
      if (solve(bx, by)) {
        cout << res << endl;
        solved = true;
        break;
      }
    }
    if (!solved) {
      cout << "This puzzle is not solvable." << endl;
    }
  }
} 

