#include <cstdio>
#include <iostream>
#include <cassert>
#include <map>

using namespace std;

map<int, bool> dp;
map<int, bool>::iterator it;

#define GET(x, i, j)   (x &  (1 << ((i) * 5 + (j))))
#define SET(x, i, j)   x = (x |  (1 << ((i) * 5 + (j))))
#define RESET(x, i, j) x = (x & ~(1 << ((i) * 5 + (j))))

bool solve(int tab) {
  // cout << "solve " << tab << endl;

  if ((it = dp.find(tab)) != dp.end()) {
    return it->second;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (GET(tab, i, j) == 0) continue;
      for (int d = 0; d < 2; d++) {
        for (int x = 0; x < 5; x++) {
          int ni = i + d * x,
              nj = j + (1 - d) * x;
          if (ni >= 5 || nj >= 5) break;
          if (GET(tab, ni, nj) == 0) break;
          for (int dx = 0; dx <= x; dx++) {
            RESET(tab, i + d * dx, j + (1 - d) * dx);
          }
          bool res = solve(tab);
          for (int dx = 0; dx <= x; dx++) {
            SET(tab, i + d * dx, j + (1 - d) * dx);
          }
          if (res == 0) {
            return dp[tab] = 1;
          }
        }
      }
    }
  }
  return dp[tab] = 0;
}

int main() {
  assert(sizeof(int) >= 4);
  int T;
  cin >> T;
  dp[0] = 1;
  while(T--) {
    int tab = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int v;
        cin >> v;
        if (v) {
          SET(tab, i, j);
        }
      }
    }
    bool res = solve(tab);
    cout << (res ? "winning" : "losing") << endl;
  }
}

