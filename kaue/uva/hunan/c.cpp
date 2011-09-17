#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  while (n != 0 || m != 0) {
    string a[12];
    int ina = 0, inb = 0;
    int minx = m, miny = m, maxx = 0, maxy = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < (int) a[i].size(); j++) {
        if (a[i][j] == '*') ina++;
      }
      // cout << a[i] << endl;
    }
    string b[12];
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      for (int j = 0; j < (int) b[i].size(); j++) {
        if (b[i][j] == '*') {
          minx = min(minx, i);
          miny = min(miny, j);
          maxx = max(maxx, i);
          maxy = max(maxy, j);
          inb++;
        }
      }
      // cout << b[i] << endl;
    }

    int sx = maxx - minx + 1;
    int sy = maxy - miny + 1;

    // cout << "minx: " << minx << " miny: " << miny << " maxx: " <<
      // maxx << " maxy: " << maxy << " sx: " << sx << " sy: " << sy << endl;

    if (ina != 2 * inb) {
      goto ENDWRONG;
    }

    for (int bx = 0; bx + sx - 1 < n; bx++) {
      for (int by = 0; by + sy - 1 < n; by++) {
        bool found = false;
        bool gone[12][12] = {{0}};
        for (int i = 0; i < sx && !found; i++) {
          for (int j = 0; j < sy && !found; j++) {
            if (a[bx + i][by + j] == '.' && b[i + minx][j + miny] == '*') {
              found = true;
            } else if (a[bx + i][by + j] == '*' &&
                b[i + minx][j + miny] == '*') {
              gone[bx + i][by + j] = true;
            }
          }
        }
        if (found) continue;
        // cout << "bx: " << bx << " by: " << by << endl;
        int first = by + 1;
        for (int ex = bx; ex + sx - 1 < n; ex++) {
          for (int ey = first; ey + sy - 1 < n; ey++) {
            bool found = false;
            for (int i = 0; i < sx && !found; i++) {
              for (int j = 0; j < sy && !found; j++) {
                if((a[ex + i][ey + j] == '.' && b[i + minx][j + miny] == '*') ||
                  (a[ex + i][ey + j] == '*' && b[i + minx][j + miny] == '.' &&
                   !gone[ex + i][ey + j]) ||
                  (a[ex + i][ey + j] == '*' && b[i + minx][j + miny] == '*' &&
                   gone[ex + i][ey + j])) {
                  found = true;
                }
              }
            }
            if (!found) {
              cout << '1' << endl;
              goto END;
            }
          }
          first = 0;
        }
      }
    }

ENDWRONG:
    cout << '0' << endl;
END:

    cin >> n >> m;
  }
}
