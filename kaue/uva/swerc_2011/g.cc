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

const int MAX = 1000010;
int v[MAX];
int presum[MAX];
int minpresum[MAX];
int minpresumind[MAX];
int postsum[MAX];
int minpostsum[MAX], minpostsumind[MAX];
bitset<MAX> valid;
 
int main() {
  int n;
  while (scanf("%d", &n) && n > 0) {
    ri {
      scanf("%d", &v[i]);
    }

    priority_queue<pair<int, int> > q;
    presum[0] = 0;
    ri {
      presum[i + 1] = presum[i] + v[i];
      //cout << presum[i + 1] << ' ';
      q.push(make_pair(-presum[i + 1], i));
    }
    //cout << endl;
    minpresum[0] = INT_MAX;
    ri {
      minpresum[i + 1] = min(minpresum[i], presum[i + 1]);
    }

    int res = 0;
    ri {
      int left = minpresum[i];
      if (i == 0) left = 0;
      int right = presum[n] - presum[i];
      //ppn(left); ppn(right); ppn(left + right);
      if (left + right < 0) continue;
      int other;
      int index = -1;
      while (index < i) {
        other = -q.top().first;
        index = q.top().second;
        if (index < i) {
          q.pop();
        }
      }
      //ppn(other); ppn(presum[i]); ppn(other - presum[i]);
      if (other - presum[i] < 0) continue;

      res++;
    }

    printf("%d\n", res);
  }
}
