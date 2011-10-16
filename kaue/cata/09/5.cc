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

class Tree {
public:
  Tree() : cnt(0) {}
  void add(char *s) {
    char c = *s;
    if (!c) return;
    child[c].cnt++;
    child[c].add(s + 1);
  }
  void print(char *s, bool first = false) {
    char c = *s;
    if (!c) return;
    cout << ' ';
    cout << child[c].cnt;
    if (!child[c].cnt) return;
    child[c].print(s + 1);
  }
  int cnt;
  map<char, Tree> child;
};
 
int main() {
  char line[10000];
  Tree t;
  while (cin.getline(line, 10000)) {
    //ppn(line);
    char first[5000], second[5000];
    int cnt = sscanf(line, "%s %s", first, second);
    if (cnt == 2) {
      t.add(first);
      //ppn(first);
      //ppn(second);
    } else {
      cout << first << ":";
      t.print(first);
      cout << endl;
      //ppn(first);
    }
  }
} 

