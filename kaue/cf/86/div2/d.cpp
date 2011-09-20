#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

typedef unsigned long long ull;

int main() {
  string t, sbegin, send;
  cin >> t >> sbegin >> send;
  int n = (int) t.size(),
      nb = (int) sbegin.size(),
      ne = (int) send.size();

  ull hash[2010], hashbegin, hashend, pot[2010];
  hash[0] = hashbegin = hashend = 0;
  pot[0] = 1;
  for (int i = 0; i < n; i++) {
#define BASE 3137ULL
    hash[i + 1] = hash[i] * BASE + t[i] - 'a';
    pot[i + 1] = pot[i] * BASE;
  }
  for (int i = 0; i < nb; i++) {
    hashbegin = hashbegin * BASE + sbegin[i] - 'a';
  }
  for (int i = 0; i < ne; i++) {
    hashend = hashend * BASE + send[i] - 'a';
  }

  /*
  for (int i = 0; i < n; i++) {
    cout << hash[i] << " ";
  }
  cout << endl;
  cout << "hashbegin: " << hashbegin << endl;
  cout << "end; " << hashend << endl;//*/

  ull res = 0;
  for (int len = max(nb, ne); len <= n; len++) {
    set<ull> subs;
    for (int i = 0; i + len - 1 < n; i++) {
      if (hash[i + nb] - hash[i] * pot[nb] != hashbegin) continue;
      if (hash[i + len] - hash[i + len - ne] * pot[ne] != hashend) continue;
      subs.insert(hash[i + len] - hash[i] * pot[len]);
    }
    res += subs.size();
  }
  cout << res << endl;
}
