#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int arrival[110];
    int departure[110];
    int count[1010] = {0};
    for (int i = 0; i < n; i++) {
      cin >> arrival[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> departure[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = arrival[i]; j < departure[i]; j++) {
        count[j]++;
      }
    }
    int res = count[0];
    for (int i = 1; i <= 1000; i++) {
      res = max(res, count[i]);
    }

    cout << res << endl;
  }
}
