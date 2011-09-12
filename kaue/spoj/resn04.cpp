#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      res ^= v / (i + 1);
    }
    cout << (res ? "ALICE" : "BOB") << endl;
  }
}
