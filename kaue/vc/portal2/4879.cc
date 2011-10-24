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

string pat[] = {
  "ssst", "sssl", "sssh", "sssi",
  "sssf", "sssb", "sssk",
  "sss", // maybe sss*
  "ssf", "ssb", "ssk",
  "ssi",
  "ss*", "ss",
  "st", "sl", "sh", "si",
  //"sf", "sb", "sk",
  "s*",
  "sffl", "sffi", "sfl", "sfi", "sff",
  "sf", "sb", "sk", "s",
  "ffl", "ffi",
  "fl", "fi", "ff",
  "ct", "oe", "OE", "Oe", "oE", "ae", "AE", "Ae", "aE"};
string to[] = {
  "[longs]s[longst]", "[longs]s[longsl]", "[longs]s[longsh]", "[longs]s[longsi]",
  "[longs]ssf", "[longs]ssb", "[longs]ssk",
  "[longs]s[longs]",
  "[longs]sf", "[longs]sb", "[longs]sk",
  "[longssi]",
  "[longs]s*", "[longss]",
  "[longst]", "[longsl]", "[longsh]", "[longsi]",
  //"sf", "sb", "sk",
  "s*",
  "s[ffl]", "s[ffi]", "s[fl]", "s[fi]", "s[ff]",
  "sf", "sb", "sk", "[longs]",
  "[ffl]", "[ffi]",
  "[fl]", "[fi]", "[ff]",
  "[ct]", "[oe]", "[OE]", "[OE]", "[oe]", "[ae]", "[AE]", "[AE]", "[ae]"};

bool special(char c, char d) {
  return d == '*' && (!isalpha(c));
      //(c >= '0' && c <= '9'));
    //!((c >= 'a' && c <= 'z') ||
      //(c >= 'A' && c <= 'Z'));
}
 
int main() {
  int T;
  cin >> T;
  //ppn(isalpha('3'));
  assert((sizeof(pat) / sizeof(*pat)) == (sizeof(to) / sizeof(*to)));
  int npat = sizeof(pat) / sizeof(*pat);
  while (T--) {
    int t;
    cin >> t;
    cin.get();
    string line;
    getline(cin, line);
    //ppn(line);
    int n = s(line);
    cout << t << ' ';
    line += '!';
    n++;
    r(i, n - 1) {
      bool found = false;
      r(j, npat) {
        int k = s(pat[j]);
        //ppn(k);
        if (i + k > n) continue;
        string cur;
        r(l, k) {
          //ppn(l);
          cur += line[i + l];
          //ppn(cur);
        }
        //ppn(pat[j]);
        //ppn(cur);
        bool invalid = false;
        r(l, k) {
          if (cur[l] != pat[j][l] && !special(cur[l], pat[j][l])) {
            invalid = true;
            break;
          }
        }
        if (invalid) {
          continue;
        }
        found = true;
        //ppn(pat[j]);
        //ppn(cur);
        int tos = s(to[j]);
        if (to[j][tos - 1] == '*') {
          cout << to[j].substr(0, tos - 1);
          if (i + k - 1 < n - 1) {
            cout << line[i + k - 1];
          }
        } else {
          cout << to[j];
        }
        i += k - 1;
        break;
      }
      if (!found) {
        cout << line[i];
      }
    }
    cout << endl;
  }
} 

