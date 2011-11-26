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

const int MAXPATH = 100;
char text[100000], pat[MAXPATH + 10];
int f[MAXPATH + 10];

void kmpsetup(char* pat, int* f) {
  int i, k, len = strlen(pat);
  for (f[0] = -1, i = 1; i < len; i++) {
    k = f[i - 1];
    while (k >= 0) {
      if (pat[k] == pat[i - 1]) break;
      else k = f[k];
    }
    f[i] = k + 1;
  }
}

int kmpscan(char* pat, char* text, int* f) {
  int i, k, ret = -1, len = strlen(pat);
  for (i = k = 0; text[i]; ) {
    if (k == -1) { i++; k = 0; }
    else if (text[i] == pat[k]) {
      i++; k++;
      if (k >= len) { ret = i - len; break; }
    } else k = f[k];
  }
  return ret;
}
 
int main() {
  int n = 2 * MAXPATH;
  srand(0xDEADBEEF);
  r(t, 1000) {
    r(i, n) { text[i] = rand() % 10 + 'a'; }
    text[n] = 0;
    int spat = rand() % 10 + 1;
    r(i, spat) { pat[i] = rand() % 10 + 'a'; }
    pat[spat] = 0;
    int res = -1;
    r(i, n) {
      if (!strncmp(pat, text + i, spat)) {
        res = i;
        break;
      }
    }
    if (res != -1)
      printf("(%s, %s) = %i\n", text, pat, res);
    kmpsetup(pat, f);
    assert(res == kmpscan(pat, text, f));
  }
} 

