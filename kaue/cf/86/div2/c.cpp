#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool get(const string& s, int& curgender, int& curtype) {
  static string suffix[] = {
    "lios", "liala", "etr", "etra", "initis", "inites"};
  // cout << "get " << s << endl;
  for (int i = 0; i < 6; i++) {
    if (s.length() < suffix[i].length()) continue;
    int index = ((int) s.length()) - suffix[i].length();
    // cout << s.substr(index) << endl;
    if (s.substr(index) == suffix[i]) {
      curgender = i % 2;
      curtype = i / 2;
      return true;
    }
  }
  return false;
}

int main() {
  string s;
  bool bad = false;
  int gender = -1;
  int count = 0;
  int type = 0;
  while (cin >> s) {
    int curgender, curtype;
    if (!get(s, curgender, curtype)) {
      bad = true;
      break;
    }
    if (count > 0 && gender != -1 && curgender != gender) {
      bad = true;
      break;
    }
    if (count > 0 && (curtype < type || (curtype == 1 && type == 1) ||
          curtype > type + 1)) {
      bad = true;
      break;
    }
    if (count == 1 && type == 2) {
      bad = true;
      break;
    }
    count++;
    type = curtype;
    gender = curgender;
  }
  if (count > 1 && type == 0) bad = true;
  cout << (bad ? "NO" : "YES") << endl;
}
