#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n;
  cin >> n;
  int p[2010];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    // cout << "i: " << i << endl;
    int k = i;
    int cur = 1;
    while ((k = p[k] - 1) != -2) {
      // cout << "k: " << k << endl;
      cur++;
    }
    res = max(res, cur);
  }
  cout << res << endl;
}
