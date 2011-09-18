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

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  int last[100002] = {0};
  for (int i = 0; i < n; i++) {
    int res = 0;
    int v = x[i];
    // cout << "i: " << i << " v: " << v << endl;
    for (int j = 1; j <= ceil(sqrt(v)); j++) {
      if (v % j == 0) {
        // cout << "j: " << j << endl;
        if (last[j]) {
          if (last[j] - 1 >= i - y[i]) {
          } else {
            // cout << "+ " << j << endl;
            res++;
          }
        } else {
          res++;
          // cout << "! " << j << endl;
        }
        last[j] = i + 1;

        int k = v / j;
        if (k == j) continue;
        // cout << "k: " << k << endl;
        if (last[k]) {
          if (last[k] - 1 >= i - y[i]) {
          } else {
            // cout << "+ " << k << endl;
            res++;
          }
        } else {
          res++;
          // cout << "! " << k << endl;
        }
        last[k] = i + 1;
      }
    }
    cout << res << endl;
  }
}
