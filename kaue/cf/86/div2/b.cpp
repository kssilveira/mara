#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string tolow(const string& s) {
  string res;
  for (int i = 0; i < (int) s.length(); i++) {
    res += tolower(s[i]);
  }
  return res;
}

int main() {
  map<string, int> index;
  bool graph[17][17] = {{0}};
  string name[17];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    index[s] = i;
    name[i] = s;
  }
  for (int i = 0; i < m; i++) {
    string s, t;
    cin >> s >> t;
    graph[index[s]][index[t]] = graph[index[t]][index[s]] = 1;
  }
  int res = 0, resmask = 0;
  for (int mask = 0; mask < (1 << 17); mask++) {
    bool found = false;
    int count = 0;
    for (int i = 0; i < n && !found; i++) {
      if (mask & (1 << i)) {
        count++;
        for (int j = i + 1; j < n && !found; j++) {
          if ((mask & (1 << j)) && graph[i][j]) {
            found = true;
            break;
          }
        }
      }
    }
    if (!found && count > res) {
      res = count;
      resmask = mask;
    }
  }
  cout << res << endl;
  vector<string> resnames;
  for (int i = 0; i < n; i++) {
    if (resmask & (1 << i)) {
      resnames.push_back(name[i]);
    }
  }

  sort(resnames.begin(), resnames.end());
  for (int i = 0; i < res; i++) {
    cout << resnames[i] << endl;
  }
}
