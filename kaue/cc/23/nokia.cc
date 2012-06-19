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

/*
int res;

int solve(int begin, int end, int m, bool last) {
  for (int i = begin + 1; i < end; i++) {
    int next = end + 1 - begin;
    solve(begin, i, m - next, false);
    solve(i, end, m - next - left, last);
  }
}//*/
 
set<int> dp[33][33];

int values[33][2] = {{0, 0},
  {2,2},{5,5},{8,9},{12,14},{16,20},{20,27},{24,35},{29,44},{34,54},{39,65},{44,77},{49,90},{54,104},{59,119},{64,135},{70,152},{76,170},{82,189},{88,209},{94,230},{100,252},{106,275},{112,299},{118,324},{124,350},{130,377},{136,405},{142,434},{148,464},{154,495}};


int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;

    if (m >= values[n][0] && m <= values[n][1]) {
      cout << int(0) << endl;
    } else if (m >= values[n][1]) {
      cout << m - values[n][1] << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
