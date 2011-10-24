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
#define ppp(x) p(pp(x))

#define in(x) cin >> x
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

int cnt;
map<string, int> ind[2];
int graph[500][500];
int degree[500];

int add_node(const string& name, bool isverb = false) {
  //printf("add_node(%s, %d)\n", name.c_str(), isverb);
  map<string, int>::iterator it;
  if ((it = ind[isverb].find(name)) == ind[isverb].end()) {
    ind[isverb][name] = cnt;
    return cnt++;
  }
  return it->second;
}

int get_node(const string& name, bool isverb = false) {
  //printf("get_node(%s, %d)\n", name.c_str(), isverb);
  map<string, int>::iterator it;
  if ((it = ind[isverb].find(name)) == ind[isverb].end()) {
    return -1;
  }
  return it->second;
}

bool go(int from, int to) {
  if (to == -1 || from == -1) return false;
  if (from == to) return true;
  queue<int> q;
  q.push(from);
  bool gone[500] = {0};
  //printf("go(%i -> %i)\n", from, to);
  //gone[from] = true;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    //ppn(cur);
    if (cur == to) return true;
    if (gone[cur]) continue;
    gone[cur] = true;
    r(i, degree[cur]) {
      int next = graph[cur][i];
      if (next == to) return true;
      if (!gone[next]) {
        //gone[next] = true;
        q.push(next);
      }
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  char line[100];
  fgets(line, 100, stdin);
  r(t, T) {
    cnt = 0;
    ind[0].clear();
    ind[1].clear();
    memset(degree, 0, sizeof(degree));
    char res[1010];
    int nres = 0;
    //int line_size;
    while (fgets(line, 100, stdin)) {
        //line[(line_size = strlen(line)) - 2] != '!') {
      int end = strlen(line) - 1;
      while (line[end] != '.' && line[end] != '!' && line[end] != '?') end--;
      if (line[end] == '!') break;
      bool isstat = line[end] == '.';
      line[end] = 0;
      //ppn(line);
      char words[10][15];
      int nwords = sscanf(line, "%s %s %s %s %s %s", words[0], words[1],
          words[2], words[3], words[4], words[5]);
      //ppn(isstat); ppn(nwords);
      if (isstat) {
        //ppn(isstat);
        if (nwords == 3) {
          //pn("=======>1");
          int id1 = add_node(words[0]);
          int id2 = add_node(words[2], !strcmp(words[1], "can"));
          //graph[id1].push_back(id2);
          graph[id1][degree[id1]++] = id2;
        } else {
          //pn("=======>2");
          int id1 = add_node(words[3], true);
          int id2 = add_node(words[5], !strcmp(words[4], "can"));
          //graph[id1].push_back(id2);
          graph[id1][degree[id1]++] = id2;
        }
      } else {
        if (nwords == 3) {
          //pn("=======>3");
          int id1 = get_node(words[1]);
          int id2 = get_node(words[2], !strcmp(words[0], "can"));
          if (go(id1, id2)) {
            res[nres++] = 'Y';
          } else {
            res[nres++] = 'M';
          }
        } else {
          //pn("=======>4");
          int id1 = get_node(words[4], true);
          int id2 = get_node(words[5], !strcmp(words[0], "can"));
          if (go(id1, id2))  {
            res[nres++] = 'Y';
          } else {
            res[nres++] = 'M';
          }
        }
      }
    }
    res[nres] = 0;
    cout << "Case #" << t + 1 << ":\n";
    cout << res << endl;
  }
} 

