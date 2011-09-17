#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    string one = "one";
    cin >> s;
    if (s.size() == 5) {
      cout << "3" << endl;
    } else {
      int count = 0;
      for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] != one[i]) {
          count++;
        }
      }
      if (count < 2) {
        cout << "1" << endl;
      } else {
        cout << "2" << endl;
      }
    }
  }
}
