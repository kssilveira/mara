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

char line[30];
int N;
ull sum;
ull comb[10][10];
int cnt;
int sol[10];
ull fat[10];

void go(int n, int last, int start) {
  //printf("go(%d, %d, %d)\n", n, last, start);
  if (n == 0) {
    if (start != N) return;
    /*
    cout << "sol" << endl;
    r(i, cnt) {
      cout << sol[i] << ' ';
    }
    cout << endl;//*/
    ull res = comb[9][cnt];
    res *= fat[cnt];
    for (int i = 0; i < cnt; ) {
      int count = 1;
      while (i + count < cnt && sol[i + count] == sol[i]) {
        count++;
      }
      res /= fat[count];
      i += count;
    }
    sum += res;
    //ppn(res);
    return;
  }
  int cur = 0;
  for (int end = start; end + (n - 1) < N; end++) {
    cur *= 10;
    cur += line[end] - '0';
    if (cur < last) continue;
    sol[cnt - n] = cur;
    go(n - 1, cur, end + 1);
  }
}
 
int main() {
  comb[0][0] = 1;
  r(i, 10) {
    comb[i][0] = comb[i][i] = 1;
    rb(j, 1, i) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
      //cout << comb[i][j] << ' ';
    }
    //cout << endl;
  }
  //cout << endl;
  fat[0] = 1;
  rb(i, 1, 10) {
    fat[i] = i * fat[i - 1];
    //cout << fat[i] << ' ';
  }
  //cout << endl;

  int T;
  cin >> T;
  while (T--) {
    scanf("%s", line);
    N = strlen(line);
    int n = line[0] - '0';
    sum = 0;
    cnt = n;
    go(n, -1, 1);
    //ppn(sum);
    printf("%llu\n", sum);
  }
} 

