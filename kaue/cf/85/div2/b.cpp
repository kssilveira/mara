#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  if (n == 2 || ((x == n / 2 || x == n / 2 + 1) && 
        (y == n / 2 || y == n / 2 + 1))) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
