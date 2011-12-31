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
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
  string s;
  int Case = 0;
  while (getline(cin, s)) {
    Case++;
    int n = s(s);
    int tab[10][10] = {{0}};
    ri {
      int ind = s[i] - 'a';
      int x = ind / 3 + 1, y = (ind % 3) + 1;
      int dx[] = {-1, 0, 1, 0, 0},
          dy[] = {0, -1, 0, 1, 0};
      r(d, 5) {
        int nx = x + dx[d], ny = y + dy[d];
        tab[nx][ny]++;
        tab[nx][ny] %= 10;
      }
    }
    cout << "Case #" << Case << ":" << endl;
    r(i, 3) {
      r(j, 3) {
        if (j) cout << ' ';
        cout << tab[i + 1][j + 1];
      }
      cout << endl;
    }
  }
} 

