#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[12][12][12][12][12][12] = {{{{{{0}}}}}};
const int val[] = {1, 3, 5, 7, 9, 11};
int cur[6] = {0};
int sol[6] = {0};
vector<int> all;
int res;

void solve(int n) {
  for (int i = 0; i < 6; i++) {
    sol[i] = cur[i];
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < cur[i]; j++) {
      sol[i] = j;

      /*cout << "sol: ";
      for (int i = 0; i < 6; i++) {
        cout << sol[i] << " ";
      }
      cout << endl;//*/
      int v = dp[sol[0]][sol[1]][sol[2]][sol[3]][sol[4]][sol[5]];
      // cout << "v: " << v << endl;

      res = res && v;
    }
    sol[i] = cur[i];
  }
}

void fill(int n) {
  if (n == 6) {
    /*
    cout << "cur: ";
    for (int i = 0; i < 6; i++) {
      cout << cur[i] << " ";
    }
    cout << endl;//*/
    res = 1;
    solve(0);
    res = 1 - res;
    dp[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][cur[5]] = res;
    dp[0][0][0][0][0][0] = 1;
    // cout << "res: " << res << endl;
    return;
  }
  for (int i = 0; i <= val[n]; i++) {
    cur[n] = i;
    fill(n + 1);
  }
}

int main() {
  int T;
  cin >> T;

  fill(0);

  for (int t = 0; t < T; t++) {
    for (int i = 0; i < 6; i++) {
      cin >> cur[i];
    }
    cout << "Instancia " << t + 1 << endl;
    res = dp[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][cur[5]];
    cout << (res ? "sim" : "nao") << endl << endl;
  }
}
