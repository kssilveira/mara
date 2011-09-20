#include <iostream>

using namespace std;

int main() {
  int k, l;
  cin >> k >> l;
  int res = 0;
  int pot = k;
  if ((k == 1 && l != 1) || (l % k != 0)) pot = l + 1;
  while (pot < l && pot < pot * k) {
    pot *= k;
    res++;
  }
  if (pot == l) {
    cout << "YES" << endl << res << endl;
  } else {
    cout << "NO" << endl;
  }
}
