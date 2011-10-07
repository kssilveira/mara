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

vi graph[100001];
bool gone[100001] = {0};
int ND[100001] = {0};
int L[100001] = {0};
int H[100001] = {0};
int ID[100001] = {0};
string str_res;
char tempstr[100];

set<pair<int, int> > intree;

void dfsdumb(int cur, int& ind) {
  gone[cur] = 1;
  ID[cur] = ind;
  //printf("ID[%i] = %i\n", cur + 1, ind);
  int n = s(graph[cur]);
  ri {
    int next = graph[cur][i];
    if (!gone[next]) {
      dfsdumb(next, ++ind);
      intree.insert(make_pair(cur, next));
    }
  }
}
bool dfs(int cur, int par) {
  //printf("dfs(%d, %d)\n", cur + 1, par);
  gone[cur] = 1;
  ND[cur] = 1;
  int ind = ID[cur];
  L[cur] = ind;
  H[cur] = ind;
  ID[cur] = ind;
  int n = s(graph[cur]);
  ri {
    int next = graph[cur][i];
    if (!gone[next]) {
      sprintf(tempstr, "%d %d\n", cur + 1, next + 1);
      str_res += tempstr;
      if(dfs(next, cur) ||
        (L[next] == ID[next] &&
         H[next] < ID[next]+ ND[next])) {
        //cout << "error: " << tempstr << endl;
        return true;
      }
      //printf("%d: ND: %d, L: %d, H: %d\n",
          //next + 1, ND[next], L[next], H[next]);
      ND[cur] += ND[next];
      L[cur] = min(L[cur], L[next]);
      H[cur] = max(H[cur], H[next]);
    } else if (intree.find(make_pair(next, cur)) == intree.end()) {
      intree.insert(make_pair(cur, next));
      //cout << "else " << cur  + 1 << " " << next + 1 << endl;
      sprintf(tempstr, "%d %d\n", cur + 1, next + 1);
      str_res += tempstr;
      L[cur] = min(L[cur], ID[next]);
      H[cur] = max(H[cur], ID[next]);
    }
  }
  return false;
}
 
int main() {
  int n, m;
  cin >> n >> m;
  r(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int ind = 1;
  dfsdumb(0, ind);
  memset(gone, 0, sizeof(gone));
  bool res = dfs(0, -1);
  if (res) {
    cout << '0' << endl;
  } else {
    cout << str_res << endl;
  }
} 

