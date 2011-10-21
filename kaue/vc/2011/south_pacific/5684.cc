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
  int k;
  cin >> k;
  r(T, k) {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    int home = 0, present = 0, remedial = 0, abscent = 0;
    ri {
      getline(cin, line);
      //ppn(line);
      istringstream input(line);
      string ans;
      input >> ans;
      int ind = 0;
      bool found = false;
      while (input >> ans) {
        //ppn(ans);
        if (ans == "y" || ans == "yes") {
          if (ind == 0) {
            present++;
          }
          found = true;
        }
        ind++;
      }
      if (found && ind > 1) {
        home++;
      }
      if (!found && ind > 0) {
        remedial++;
      }
      if (ind == 0) {
        abscent++;
      }
    }
    printf("Roll-call: %d\n"
        "Present: %d out of %d\n"
        "Needs to study at home: %d out of %d\n"
        "Needs remedial work after school: %d out of %d\n"
        "Absent: %d out of %d\n",
        T + 1, present, n, home, n, remedial, n, abscent, n);
  }
} 

