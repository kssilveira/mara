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

int row, col;

#define ROW (1 << 6)
#define INF 1000

bitset<ROW> gone[41][ROW];
int dp[41][ROW][ROW];

int solve(int c, int last, int cur) {
  // cout << "solve(" << c << ", " << last << ", " << cur << ")" << endl;
  if (gone[c][last][cur]) return dp[c][last][cur];
  gone[c][last][cur] = 1;
  int& res = dp[c][last][cur];
  if (c == col - 1) {
    for (int r = 0; r < row; r++) {
      int ok = 0;
      for (int k = -1; k <= 1; k++) {
        int rr = r + k;
        if (rr < 0 || rr >= row) continue;
        if (cur & (1 << rr)) {
          ok = 1;
          break;
        }
      }
      if (last & (1 << r)) ok = 1;
      // if (mask & (1 << r)) ok = 1;
      if (!ok) {
        return res = -INF;
      }
    }
    int next = 0; // solve(c + 1, cur, mask);
    for (int r = 0; r < row; r++) {
        if (!(cur & (1 << r))) {
        next++;
      }
    }
    return res = next;
  }
  res = -INF;
  for (int mask = 0; mask < (1 << row); mask++) {
    int maskok = 1;
    for (int r = 0; r < row; r++) {
      int ok = 0;
      for (int k = -1; k <= 1; k++) {
        int rr = r + k;
        if (rr < 0 || rr >= row) continue;
        if (cur & (1 << rr)) {
          ok = 1;
          break;
        }
      }
      if (last & (1 << r)) ok = 1;
      if (mask & (1 << r)) ok = 1;
      if (!ok) {
        maskok = 0;
        break;
      }
    }
    if (!maskok) continue;
    int next = solve(c + 1, cur, mask);
    for (int r = 0; r < row; r++) {
      if (!(cur & (1 << r))) {
        next++;
      }
    }
    res = max(res, next);
  }
  return res;
}

int main() {
  cin >> row >> col;
  if (row > col) swap(row, col);
  for (int i = 0; i < 41; i++) {
    for (int j = 0; j < (1 << row); j++) {
      gone[i][j].reset();
    }
  }
  int res = -INF;
  for (int i = 0; i < (1 << row); i++) {
    res = max(res, solve(0, 0, i));
  }
  cout << res << endl;
}
