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

const string target = "the quick brown fox jumps over the lazy dog";

int main() {
  int T;
  cin >> T;
  bool second = false;
  string line;
  getline(cin, line);
  getline(cin, line);
  while (T--) {
    if (second) cout << endl;
    second = true;
    vector<string> lines;
    while (getline(cin, line) && !line.empty()) {
      //ppn(line);
      lines.push_back(line);
    }
    int n = s(lines);
    char go[256], back[256];
    bool found = false;
    ri {
      memset(go, 0, sizeof(go));
      memset(back, 0, sizeof(back));
      const string& line = lines[i];
      bool invalid = false;
      if (s(line) != s(target)) continue;
      r(j, s(line)) {
        if ((line[j] == ' ' && target[j] != ' ') ||
            (line[j] != ' ' && target[j] == ' ')) {
          invalid = true;
          break;
        }
        if (!go[line[j]] && !back[target[j]]) {
          go[line[j]] = target[j];
          back[target[j]] = line[j];
        } else if (go[line[j]] != target[j] ||
            back[target[j]] != line[j]) {
          invalid = true;
          break;
        }
      }
      if (!invalid) {
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "No solution." << endl;
      continue;
    }
    ri {
      const string& line = lines[i];
      r(j, s(line)) {
        cout << go[line[j]];
      }
      cout << endl;
    }
  }
} 

