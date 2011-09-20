#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> Node;
typedef vector<Node> Graph;
Graph graph[5010];

int distc[5010], distn[5010];
int j, b, c, n, s;

void dijkstra(int begin, int* distances) {
  bool gone[5010] = {0};
  priority_queue<Node> q;
  q.push(make_pair(0, begin));
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int ind = node.second, dist = node.first;
    if (gone[ind]) continue;
    gone[ind] = 1;
    distances[ind] = -dist;
    for (int i = 0; i < (int) graph[ind].size(); i++) {
      int next = graph[ind][i].second;
      if (!gone[next]) {
        q.push(make_pair(dist + graph[ind][i].first, next));
      }
    }
  }
  /*
  for (int i = 0; i < j; i++) {
    cout << distances[i] << " ";
  }
  cout << endl;//*/
}

int dfs(int begin) {
  bool gone[5050] = {0};
  stack<Node> s;
  s.push(make_pair(begin, 0));
  int res = 0;
  while (!s.empty()) {
    Node node = s.top(); s.pop();
    int ind = node.first, dist = node.second;
    if (gone[ind]) continue;
    gone[ind] = 1;
    res = max(res, dist);
    for (int i = 0; i < (int) graph[ind].size(); i++) {
      int next = graph[ind][i].second,
          cost = -graph[ind][i].first;
      if (distc[next] + cost == distc[ind] &&
          distn[next] + cost == distn[ind]) {
        s.push(make_pair(next, dist - graph[ind][i].first));
      }
    }
  }
  return res;
}

int main() {
  scanf("%d%d%d%d%d", &j, &b, &c, &n, &s);
  while (j != -1) {
    b--;
    c--;
    n--;
    for (int i = 0; i < s; i++) {
      int e1, e2, l;
      scanf("%d%d%d", &e1, &e2, &l);
      e1--;
      e2--;
      graph[e1].push_back(make_pair(-l, e2));
      graph[e2].push_back(make_pair(-l, e1));
    }

    dijkstra(c, distc);
    dijkstra(n, distn);
    int res = dfs(b);

    printf("%d %d %d\n", res, distc[b] - res, distn[b] - res);

    for (int i = 0; i < j; i++) {
      graph[i].clear();
    }

    scanf("%d%d%d%d%d", &j, &b, &c, &n, &s);
  }
}
