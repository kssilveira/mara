#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int tab[11][11] = {{0}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == 'W') {
        tab[i][j] = 1;
      } else if (c == 'P') {
        tab[i][j] = 2;
      }
    }
  }
  int dx[] = {-1, 0, 1, 0},
      dy[] = {0, -1, 0, 1};
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tab[i][j] != 1) continue;
      bool found = false;
      for (int d = 0; d < 4; d++) {
        int x = i + dx[d],
            y = j + dy[d];
        if (x < 0 || x >= n ||
            y < 0 || y >= m) continue;
        if (tab[x][y] == 2) {
          found = true;
          break;
        }
      }
      if (found) {
        res++;
      }
    }
  }
  cout << res << endl;
}
