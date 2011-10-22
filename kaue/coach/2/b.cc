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

class Data {
public:
  Data(int pp, int j) : j(j) { p = pp; }
  int p, j, jan;
};

bool compjan(const Data& l, const Data& r) {
  return l.j > r.j || (
      l.j == r.j && l.p < r.p);
}

bool comppetra(const Data& l, const Data& r) {
  if (l.j == r.j)
    return l.p < r.p;
  return l.p > r.p;
  //return l.p > r.p || (
      //l.p == r.p && l.j < r.j);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string name;
    cin >> name;
    vector<Data> v;
    ri {
      int p, j;
      cin >> p >> j;
      v.push_back(Data(p, j));
    }

    sort(all(v), compjan);
    //reverse(all(v));
    //ppn(name);
    ri {
      v[i].jan = i;
    }
    //*
    ri {
      cout << v[i].p << ", " << v[i].j << ": " << v[i].jan<< endl;
    }
    cout << endl;//*/

    sort(all(v), comppetra);

    //*
    ri {
      cout << v[i].p << ", " << v[i].j << ": " << v[i].jan<< endl;
    }
    cout << endl;//*/

    int cnt = n / 2;
    if (n % 2 && name == "Jan") cnt++;

    int resp = 0, resj = 0;
    int cntjan = cnt, cntpetra = n - cnt;
    int creditjan = 0;
    if (name == "Jan") creditjan = 1;
    ri {
      ppn(resp); ppn(resj); ppn(cntjan);
      ppn(cntpetra); ppn(creditjan);
      int next = v[i].jan;
      ppn(next);
      if (cntpetra) {
        if (next < cntjan) {
          if (creditjan) {
            creditjan--;
            resj += v[i].j;
            continue;
          } else {
            cntjan++;
          }
        }
        cntpetra--;
        resp += v[i].p;
        creditjan++;
      } else {
        resj += v[i].j;
      }
    }
    cout << resp << " " << resj << endl;
  }
} 

