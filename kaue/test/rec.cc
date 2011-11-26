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

struct REC {
  int x,y,xx,yy; // rectangle from x->xx, y->yy
  void input() {cin>>x>>y>>xx>>yy;}
};

REC rec[101];
map<int, int> mp;
vector<int> vt;
int bd[500][500];

int main() {
  int R = 0, n = 0, x, y;
  r(i, R) {
    rec[i].input();
  }
  vt.clear();
  r(i, R) {
    vt.push_back(rec[i].x); vt.push_back(rec[i].y);
    vt.push_back(rec[i].xx); vt.push_back(rec[i].yy);
  }
  vt.push_back(-100000000);
  vt.push_back(100000000);
  sort(all(vt));
  mp.clear();
  r(c, s(vt)) {
    mp[vt[c]]=c;
  }
  memset(bd, 0, sizeof(bd));
  ri {
    for(x=mp[rec[i].x]; x<mp[rec[i].xx]; x++)
      for(y=mp[rec[i].y]; y<mp[rec[i].yy]; y++)
        bd[x][y]=1;
  }
}

