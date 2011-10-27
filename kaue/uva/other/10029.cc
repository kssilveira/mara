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

#include <tr1/unordered_map>
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

const ull BASE = 5347, ALPHA = 'z' - 'a' + 1;

typedef tr1::unordered_map<ull, int> Map;
Map ind[20];
char input[25010][30];
int best[25010] = {0};
 
int main() {
  int sizeinput = 0;
  while (fgets(input[sizeinput], 30, stdin)) {
    sizeinput++;
  }

  int res = 0;
  r(fcur, sizeinput) {
    char* s = input[fcur];
    //ppn(s);
    int cur = fcur + 1;
    best[cur] = 1;

    ull hashbegin[20] = {0}, hashend[20] = {0};
    ull base[20] = {0};
    int n = strlen(s);
    //*
    r(i, n) {
      s[i] -= 'a' - 1;
    }//*/
    hashbegin[0] = 0;
    hashend[n] = 0;
    base[0] = 1;
    rb(i, 1, n + 1) {
      base[i] = base[i - 1] * BASE;
      hashbegin[i] = hashbegin[i - 1] * BASE + s[i - 1];
      hashend[n - i] = s[n - i] * base[i - 1] + hashend[n - i + 1];
    }
    /*
    r(i, n + 1) {
      cout << hashbegin[i] << ' ';
    }
    cout << endl;

    r(i, n + 1) {
      cout << hashend[i] << ' ';
    }
    cout << endl;//*/

    //ppn(best[cur]);

    //cout << "changing" << endl;
    r(i, n) { // changing
      rb(j, 1, ALPHA + 1) {
        ull other = (hashbegin[i] * BASE + j) * base[n - i - 1] +
          hashend[i + 1];
        //ppn(other);
        Map::const_iterator it = ind[n].find(other);
        if (it != ind[n].end()) {
          int indother = it->second;
          best[cur] = max(best[cur], best[indother] + 1);
          res = max(res, best[cur]);
          //ppn(other);
          //graph[cur].push_back(indother);
          //graph[indother].push_back(cur);
        }
      }
    }

    //ppn(best[cur]);

    //cout << "deleting" << endl;
    r(i, n) { // deleting
      ull other = hashbegin[i] * base[n - i - 1] + hashend[i + 1];
      Map::const_iterator it = ind[n - 1].find(other);
      if (it != ind[n - 1].end()) {
        int indother = it->second;
        best[cur] = max(best[cur], best[indother] + 1);
        res = max(res, best[cur]);
        //ppn(other);
        //graph[cur].push_back(indother);
        //graph[indother].push_back(cur);
      }
    }

    //ppn(best[cur]);

    //cout << "adding" << endl;
    r(i, n + 1) { // adding
      rb(j, 1, ALPHA + 1) {
        ull other = (hashbegin[i] * BASE + j) * base[n - i] +
          hashend[i];
        //ppn(other);
        Map::const_iterator it = ind[n + 1].find(other);
        if (it != ind[n + 1].end()) {
          int indother = it->second;
          best[cur] = max(best[cur], best[indother] + 1);
          res = max(res, best[cur]);
          //ppn(other);
          //graph[cur].push_back(indother);
          //graph[indother].push_back(cur);
        }
      }
    }

    //ppn(best[cur]);

    ind[n][hashbegin[n]] = cur;
  }

  cout << res << endl;
} 

