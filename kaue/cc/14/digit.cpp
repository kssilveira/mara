#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int count(int n) {
  int res = 0;
  while (n) {
    n /= 10;
    res++;
  }
  return res;
}

int solve(int n);

map<int, int> memo, memorev;

int solverev(int n) {
  // cout << "solverev(" << n << endl;
  if (memorev[n]) return memorev[n];
  //*
  int& res = memorev[n];
  res = -1;

  int v = n;
  int d = count(n);

  for (int i = 0; i < d; i++) {
    int first = v % 10;
    int td = count(v);
    for (int j = 0; j < td - 1; j++) {
      first *= 10;
    }
    int nv = first + v / 10;
    res = max(res, nv);
    v = nv;
    // cout << nv << endl;
    res = max(res, solve(nv));
  }//*/
  return res;
}

int solve(int n) {
  // cout << "solve(" << n << endl;

  if (n == 0) return 0;
  if (memo[n]) return memo[n];

  int d = count(n);
  int v = n;
  int& res = memo[n];
  res = -1;

  // cout << "v: " << v << endl;
  for (int i = 0; i < d; i++) {
    int first = v;
    int nv = 0;
    int pot = 10;
    while (first >= 10) {
      nv += (first % 10) * pot;
      pot *= 10;
      first /= 10;
    }
    nv += first;
    // cout << nv << endl;
    res = max(res, nv);
    v = nv;
    res = max(res, solverev(nv));
  }

  res = max(res, solverev(n));

  return res;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memo.clear();
    memorev.clear();
    int n;
    cin >> n;
    int res = solve(n);
    cout << res << endl;
  }
}
