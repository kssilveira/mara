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
  int k, n;
  cin >> k >> n;
  vector<string> a, b;
  r(i, k) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  ri {
    string s;
    cin >> s;
    b.push_back(s);
  }
  ri {
    bool good = false;
    string cur = b[i];
    if (cur.size() >= 47) {
      good = true;
    } else {
      r(j, k) {
        string other = a[j];
        for (int st = 0; st + s(other) <= s(cur); st++) {
          bool found = false;
          r(l, s(other)) {
            if (other[l] != cur[st + l]) {
              found = true;
              break;
            }
          }
          if (!found) {
            good = true;
            break;
          }
        }
        if (good) break;
      }
    }
    cout << (good ? "Good" : "Bad") << endl;
  }
} 

