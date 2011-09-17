#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

using namespace std;

    vector<int> DIV;
    vector<int> EXP;
  vector<int> x;
  int res;

    vector<int> low, high;

void count(int prod, int ind, int i, int y) {
  if (ind == (int) DIV.size()) {
    // cout << "prod: " << prod << endl;
    repb(j, i - y, i) {
      // cout << "x[" << j << "]:" << x[j] << endl;
      if (x[j] % prod == 0) {
        return;
      }
    }
    // cout << "prod: " << prod << endl;
    res++;
    return;
  }
  int mul = 1;
  rep(j, low[ind]) {
    mul *= DIV[ind];
  }
  repbe(j, low[ind], high[ind]) {
    count(prod * mul, ind + 1, i, y);
    mul *= DIV[ind];
  }
}

int main() {
  vector<int> p;
  p.push_back(2);
  repb(i, 3, 100000) {
    bool found = false;
    repb(j, 1, (int) p.size()) {
      if (i % p[j] == 0) {
        found = true;
        break;
      }
    }
    if (!found) {
      p.push_back(i);
    }
    i++;
  }

  // cout << "size:" << p.size() << endl;

  // rep(j, 10) {
    // cout << p[j] << endl;
  // }

  int n;
  int y;
  cin >> n;
  x.resize(n);
  rep(i, n) {
    // cout << "i: " << i << endl;
    DIV.clear();
    EXP.clear();
    cin >> x[i] >> y;
    int tx = x[i];
    rep(j, (int) p.size()) {
      if (tx == 1) break;
      if (p[j] * p[j] > tx) {
        DIV.push_back(tx);
        EXP.push_back(1);
        break;
      }
      if(tx % p[j] == 0) {
        DIV.push_back(p[j]);
        EXP.push_back(0);
        int ind = EXP.size() - 1;
        while(tx % p[j] == 0) {
          EXP[ind]++;
          tx /= p[j];
        }
      }
    }
    low.clear();
    high.clear();
    rep(j, (int) DIV.size()) {
      low.push_back(0);
      high.push_back(EXP[j]);
    }

    res = 0;

    vector<int> cur(DIV.size());

    while(1) {
      int tot = 1;
      rep(j, (int) DIV.size()) {
        tot *= high[j] - low[j] + 1;
        cout << "low " << low[j] << " high " << high[j] << endl;
      }
      cout << "tot: " << tot << endl;
      if (tot <= 2) break;
      int prod = 1;
      rep(j, (int) DIV.size()) {
        cur[j] = (high[j] + low[j]) / 2;
        if (high[j] == low[j] + 1 && rand() % 2) {
          cur[j] = high[j];
        }
        rep(k, cur[j]) {
          prod *= DIV[j];
        }
      }

      cout << "prod: " << prod << endl;
      bool found = false;
      repb(j, i - y, i) {
        cout << "x[" << j << "]:" << x[j] << endl;
        if (x[j] % prod == 0) {
          found = true;
          break;
        }
      }
      if (found) {
        rep(j, (int) DIV.size()) {
          low[j] = cur[j];
        }
      } else {
        rep(j, (int) DIV.size()) {
          high[j] = cur[j];
        }
      }
        // cout << "prod: " << prod << endl;
        // res++;
    }

    rep(j, (int) DIV.size()) {
      cout << "cur[" << j << "]:" << cur[j] << endl;
    }

    res = 1;
    rep(j, (int) DIV.size()) {
      res *= EXP[j] - high[j] + 1;
    }

    res--;
    cout << "res:" << res << endl;

    count(1, 0, i, y);
    cout << res << endl;
  }
}
