#include <iostream>
#include <vector>

using namespace std;

bool clap(int x) {
  if (x % 7 == 0)
    return true;

  while(x > 1) {
    if (x % 10 == 7)
      return true;
    x = x / 10;
  }

  return false;
}

int main() {
  int m, n, k;
  while (cin >> n >> m >> k) {
    if (n == 0 && m == 0 && k == 0)
      break;

  bool found = false;
  long cur = m;
  long claps = 0;
  bool turn = false;

  while (1) {
    if (clap(cur))
      claps++;

    if (claps == k) 
      break;
  
    if (m == 1) {
      cur += (n - 1) * 2;
    } else if (m == n) {
      cur += (m-1) * 2;
    } else if (!turn) {
      cur += (n - m) * 2;
    } else {
      cur += (m - 1) * 2;
    }
    turn = !turn;
  }
  cout << cur << endl;
  }
}

