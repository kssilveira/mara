#include <iostream>
#include <cstdio>
#include <bitset>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

#define MAX (300000000)

bitset<(MAX >> 1) + 1> notprime;

int main() {
  notprime.reset();
  int end = sqrt(MAX) + 2;

  //*
  // int primes = 0;
  // prime[primes++] = 2;
  notprime[0] = 1;
  for (int i = 3; i < end; i+=2) {
    if (!notprime[i >> 1]) {
      // prime[primes++] = i;
      for (int j = i + i + i; j < MAX; j += i + i) {
        notprime[j >> 1] = 1;
      }
    }
  }

  // for (int i = end - end % 2 - 1; i < MAX; i += 2) {
    // if (!notprime[i]) {
      // prime[primes++] = i;
    // }
  // }//*/

  /*
  cout << "primes: " << primes << endl;
  for (int i = 0; i < 10; i++) {
    cout << prime[primes - 1 - i] << " ";
  }
  cout << endl;//*/

  ull l, r;
  cin >> l >> r;
  ull res = 0;
  if (l <= 2 && r >= 2) res++;
  // cout << res << endl;
  while (l % 4 != 1) l++;
  // cout << res << endl;
  for (ull i = l; i <= r; i += 4) {
    if (!notprime[i >> 1]) {
      res++;
    }
  }
  cout << res << endl;
}
