#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n != 0) {
    int i = 1;
    while (i < n) {
      i = 2 * i + 1;
    }

    if (i == n) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
    }

    cin >> n;
  }
}
