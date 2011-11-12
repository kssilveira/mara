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
  int b, s;
  while (scanf("%d%d", &b, &s) && b > 0) {
    //ppn(b); ppn(s);
    int previous[100010], next[100010];
    r(i, b) {
      previous[i] = i - 1;
      next[i] = i + 1;
    }

    r(i, s) {
      int l, r;
      //cin >> l >> r;
      scanf("%d%d", &l, &r);
      l--;
      r--;
      //ppn(l); ppn(r);
      int begin = previous[l];
      int end = next[r];
      if (begin != -1) {
        next[begin] = end;
      }
      if (end != -1) {
        previous[end] = begin;
      }
      
      //ppn(begin); ppn(end);
      if (begin != -1) {
        //cout << begin + 1;
        printf("%d", begin + 1);
      } else {
        //cout << '*';
        printf("*");
      }
      //cout << ' ';
      printf(" ");
      if (end != b) {
        //cout << end + 1;
        printf("%d", end + 1);
      } else {
        //cout << '*';
        printf("*");
      }
      //cout << endl;
      printf("\n");
    }
    //cout << "-" << endl;
    printf("-\n");
  }
} 

