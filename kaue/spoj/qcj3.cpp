#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      for (int j = 0; j < v; j++) {
        res ^= (i + 1);
      }
    }
    cout << (res ? "Tom" : "Hanks") << " Wins\n";
  }
}
