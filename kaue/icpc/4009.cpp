#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int r, c;
  int v[21][21];
  scanf("%i %i", &r, &c);
  while (r != 0 || c != 0) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        char c;
        scanf(" %c", &c);
        v[i][j] = c;
      }
    }

    int R = r, C = c;

    int gone[21][21] = {{0}};
    int i = 0, j = 0;
    int d = 0;
    int r0 = -1, c0 = 0;
    r = C; c = R;
    string out;
    int dir[4][2] = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};
    while ((int) out.size() < R * C) {
      // cout << out << endl;
      if (!gone[j][i]) {
        gone[j][i] = true;
        out += v[j][i];
      }
      i += dir[d][0];
      j += dir[d][1];
      if (i == r && j == c0) {
        i = --r;
        d++;
      }
      if (i == r && j == c) {
        j = --c;
        d++;
      }
      if (i == r0 && j == c) {
        i = ++r0;
        d++;
      }
      if (i == r0 && j == c0 + 1) {
        j = ++c0;
        d++;
      }
      d %= 4;
    }

    // char dif = ('J' - 'C' + 127) % 127;
    char dif = 'J' - 'C';

    // cout << out << endl;
    for (int i = 0; i < (int) out.size(); i++) {
      out[i] -= dif;
      if (out[i] < 0) {
        out[i] += 127;
      }
      out[i] %= 127;
    }
    cout << out << endl;

    scanf("%i %i", &r, &c);
  }
}
