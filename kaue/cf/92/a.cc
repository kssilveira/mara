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
  bitset<1010> isnotprime;
  isnotprime[2] = true;
  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i < 1010; i += 2) {
    if (!isnotprime[i]) {
      primes.push_back(i);
      for (int j = i + i; j < 1010; j += i) {
        isnotprime[j] = true;
      }
    }
  }

  /*
  r(i, 10) {
    cout << primes[i] << ' ';
  }
  cout << endl; //*/

  string s;
  cin >> s;
  int n = s(s);
  //ppn(n);
  int cnt[300] = {0};
  r(i, n) {
    cnt[int(s[i])]++;
  }

  vector<pair<int, char> > v;
  r(i, 256) {
    if (cnt[i] > 0) {
      v.push_back(make_pair(cnt[i], char(i)));
    }
  }

  char res[1010] = {0};
  bool invalid = false;
  int total = 0;
  sort(all(v));
  reverse(all(v));
  r(i, s(primes)) {
    int num = n / primes[i];
    /*
    r(i, s(v)) {
      printf("(%d, %c) ", v[i].first, v[i].second);
    }//*/
    //ppn(num);
    if (num <= 1) {
      r(i, n) {
        //cout << i << " " << res[i] << endl;
        if (res[i] != 0) continue;
        bool found = false;
        r(j, s(v)) {
          if (v[j].first == 0) continue;
          res[i] = v[j].second;
          v[j].first--;
          found = true;
          break;
        }
        //cout << i << " " << res[i] << endl;
        if (!found) {
          invalid = true;
          break;
        }
      }
      break;
    }
    //v[0].first -= num;
    //ppn(primes[i]);
    r(j, num) {
      int ind = (j + 1) * primes[i] - 1;
      if (!res[ind]) {
        res[ind] = v[0].second;
        v[0].first--;
      }
      //res[(j + 1) * primes[i] - 1] = v[0].second;
    }
    if (v[0].first < 0) {
      invalid = true;
      break;
    }
  }
  if (invalid) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl << res << endl;
  }

} 

