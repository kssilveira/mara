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
#include <iomanip>
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
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)

#define p(x) cout << x << " "
#define pl cout << endl
#define pn(x) cout << x << endl
#define pv(v) ri { p(v[i]); } pl;
#define pm(m) ri { rjm { p(m[i][j]); } pl; } pl;
#define pp(x) " "#x" " << x
#define ppn(x) pn(pp(x))
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()

#define pb push_back
#define mp make_pair
#define nl cout << endl
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

int mat[3][3];

int n = 3;

/*
bool solve(int cur) {
  if (cur == 0) return;
  if (memo[cur]) return;
  r(m, 9) {
    int x = mx[m], y = my[m];
    r(d, 4) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx > 2 ||
          ny < 0 || ny > 2) continue;

    }
  }
}//*/

int pot[10];

int get(int cur, int d) {
  return (cur / pot[d]) % 10;
}

int set_val(int cur, int d, int val) {
  int res = cur - get(cur, d) * pot[d];
  return res + val * pot[d];
}

int get_next(int cur, int m) {

    int dx[] = {-1, 0, 1, 0, 0},
        dy[] = {0, -1, 0, 1, 0};

        int x = m / 3, y = m % 3;
        int next = cur;

        r(d, 5) {
          int nx = x + dx[d], ny = y + dy[d];
          if (nx < 0 || nx > 2 ||
              ny < 0 || ny > 2) continue;
          int ind = 3 * nx + ny;
          //ppn(ind);
          int val = get(cur, ind);
          next = set_val(next, ind, (val + 9) % 10);
        }
  return next;
}

const int MAX = 1000000000;

bitset<MAX> in_q;
char par[MAX];
//map<int, pair<int, int> > par;
 
int main() {
  pot[0] = 1;
  rb(i, 1, 10) {
    pot[i] = pot[i - 1] * 10;
  }
  string s;

  while (getline(cin, s)) {
    //par.clear();
    memset(par, 0, sizeof(par));
    in_q.reset();

    int begin = 0;
    ri {
      rj {
        begin *= 10;
        scanf("%d", &mat[i][j]);
        if (mat[i][j]) {
          begin += mat[i][j];
        }
      }
    }

    //ppn(begin);

    queue<int> q;
    q.push(0);
    bool found = false;

    //par[0] = make_pair(-1, -1);
    //par[0][0] = par[0][1] = -1;
    par[0] = -1;
    in_q[0] = true;
    int dx[] = {-1, 0, 1, 0, 0},
        dy[] = {0, -1, 0, 1, 0};
    int seen = 0;
    while (!q.empty()) {
      int cur = q.front(); q.pop();

      seen++;

      if (!(seen % 100000)) printf(".\n");

      //ppn(cur);

      if (cur == begin) {
        found = true;
        break;
      }

      r(m, 9) {
        int x = m / 3, y = m % 3;
        int next = cur;
        //ppn(x); ppn(y); ppn(m);
        r(d, 5) {
          int nx = x + dx[d], ny = y + dy[d];
          if (nx < 0 || nx > 2 ||
              ny < 0 || ny > 2) continue;
          int ind = 3 * nx + ny;
          //ppn(ind);
          int val = get(cur, ind);
          next = set_val(next, ind, (val + 1) % 10);
        }

        //ppn(next);

        if (!in_q[next]) {
          in_q[next] = true;
          q.push(next);
          //par[next] = make_pair(cur, m);
          //par[next][0] = cur;
          //par[next][1] = m;
          par[next] = m;
        }
      }

    }

    if (!found) {
      cout << "No solution." << endl;
    } else {
      string res;
      int cur = begin;
      //while (par[cur].first != -1) {
      //while (par[cur][0] != -1) {
      while (par[cur] != -1) {
        //res += 'i' - par[cur].second;
        //res += 'i' - par[cur][1];
        res += 'i' - par[cur];
        //cur = par[cur].first;
        //cur = par[cur][0];
        cur = get_next(cur, par[cur]);
      }
      reverse(all(res));
      cout << res << endl;
    }

    getline(cin, s);

    //solve(begin);
    //cout << solution(begin) << endl;
  }
} 

