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

int ind[300];
int perm[10];
int v[10];

class Tree {
public:
  Tree() : op(0) {}
  int eval() {
    if (op == 0) {
      return v[perm[ind[val]]];
    }
    if (op == '+') {
      return child[0].eval() + child[1].eval();
    }
    if (op == '*') {
      return child[0].eval() * child[1].eval();
    }
    if (op == '-') {
      return child[0].eval() - child[1].eval();
    }
  }
  vector<Tree> child;
  int val;
  char op;
};

int nval;

void parse(Tree& t) {
  char c;
  scanf(" %c", &c);
  if (c == '(') {
    t.child.resize(2);
    parse(t.child[0]);
    scanf("%c", &t.op);
    parse(t.child[1]);
    scanf("%c", &c); // ')'
  } else {
    t.val = c - 'a';
    ind[t.val] = nval++;
  }
}
 
int main() {
  int n;
  while (scanf("%d", &n) && n > 0) {
    ri {
      scanf("%d", &v[i]);
    }
    int result;
    scanf("%d", &result);
    Tree t;
    nval = 0;
    parse(t);
    ri {
      perm[i] = i;
    }
    bool found = false;
    do {
      int res = t.eval();
      if (res == result) {
        found = true;
        break;
      }
    } while (next_permutation(perm, perm + n));
    printf("%s\n", found ? "YES" : "NO");
  }
} 

