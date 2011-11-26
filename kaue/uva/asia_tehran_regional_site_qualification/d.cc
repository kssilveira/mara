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

char line[3000];
int N;

int parse(int start, int& last, bool& impossible, int depth, int ind) {
  //printf("parse(%d, %d, %d)\n", start, depth, ind);
  int cur = line[start] - '0';
  int res = 0;
  if (start == N) {
    impossible = true;
    return -1;
  }
  if (impossible) {
    return -1;
  }
  if (cur == 2) {
    int nlast = start + 1;
    r(i, 4) {
      res = max(res, 1 + parse(nlast, nlast, impossible, depth + 1, i));
    }
    last = nlast;
  } else {
    last = start + 1;
  }
  return res;
}
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%s", line);
    N = strlen(line);
    bool impossible = false;
    r(i, N - 4) {
      if (line[i] != '2') continue;
      int cnt[3] = {0};
      rb(j, i + 1, i + 5) {
        cnt[line[j] - '0']++;
      }
      if (cnt[0] == 4 || cnt[1] == 4) {
        impossible = true;
      }
    }
    int last = 0;
    int val = parse(0, last, impossible, 0, 0);
    if (impossible || last != N) {
      printf("Not Possible\n");
    } else {
      printf("2^%d*2^%d\n", val, val);
    }
  }
} 

