#include <algorithm>
#include <iomanip>
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
  string s;
  while (cin >> s) {
    //ppn(s);
    stack<char> st;
    stack<int> ind;
    vector<ld> op;
    for (int i = 0; i < (int)s.size(); i++) {
      char cur = s[i];
      //ppn(i);
      //ppn(cur);
      if (cur == 'S' || cur == 'P') {
        st.push(cur);
        ind.push(s(op));
      } else if (cur == 'R') {
        ld r = 0;
        int cnt = 0;
        while (s[i + cnt] != ')') cnt++;
        sscanf(s.substr(i, cnt).c_str(), "R(%Lf)", &r);
        //ppn(r);
        i += cnt;
        op.push_back(r);
      } else if (cur == ')') {
        //ppn(s(st));
        char what = st.top(); st.pop();
        int where = ind.top(); ind.pop();
        //ppn(what);
        //ppn(where);
        ld res = 0;
        if (what == 'S') {
          for (int i = where; i < s(op); i++) {
            res += op[i];
          }
        } else {
          for (int i = where; i < s(op); i++) {
            res += 1. / op[i];
          }
          res = 1. / res;
        }

        op.resize(where);
        //ppn(res);
        op.push_back(res);

        //ppn(s(op));
        //op.clear();
      }
    }
    cout << fixed << setprecision(3) << op[0] << endl;
    //p("next case\n\n");
  }
} 
