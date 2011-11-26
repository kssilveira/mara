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
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

// longest palindromic substring O(n)
// UVa Shiraz University Local Contest 2011 - 26/11
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=12&page=show_contest&contest=294
// B (Ball Blasting Game)
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    char line[100010];
    scanf("%s", line);
    int n = strlen(line);
    //* DESCOMENTAR!!!
    int cur = 1;
    rb(i, 1, n) {
      if (line[i] != line[i - 1]) {
        line[cur++] = line[i];
      }
    }
    line[cur] = 0;
    n = strlen(line);//*/
    //ppn(line);
    int dp[100010];
    r(i, n) {
      dp[i] = 1;
    }
    int res = 1;
    rb(i, 1, n) {
      //ppn(i);
      //ppn(dp[i]);
      /*
      r(j, i + 1) {
        cout << dp[j] << ' ';
      }
      cout << endl;//*/
      int size = dp[i];
      while (i - size >= 0 && i + size < n &&
          line[i - size] == line[i + size]) {
        size++;
      }
      dp[i] = size;
      res = max(res, dp[i]);
      for (int j = i - 1; j >= 0; j--) {
        if (j - dp[j] <= i - dp[i]) {
          dp[i + (i - j)] = max(dp[i + (i - j)],
              j - (i - dp[i]));
          i += i - j - 1;
          break;
        }
        //if (j + dp[j] >= i) {
          //i += i - j - 1;
          //break;
        //}
      }
    }
    printf("%d\n", res);
  }
} 

