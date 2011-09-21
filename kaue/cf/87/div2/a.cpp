#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n;
  cin >> n;
  int res = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cur = cur - a + b;
    res = max(res, cur);
    // cout << cur << endl;
  }
  cout << res << endl;
}
