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

int g_ind = 0;

struct Tree* get_tree();

struct Tree {
  Tree() : op('?'), var('!'), neg(false) {};
  void print() {
    if (neg) {
      cout << "~";
    }
    if (!child.empty()) {
      cout << "(" << op << "";
      r(i, s(child)) {
        child[i]->print();
      }
      cout << ")";
    } else {
      cout << "" << var << "";
    }
  }
  void print(ostringstream& out) {
    if (neg) {
      out << "~";
    }
    if (!child.empty()) {
      out << "(" << op << "";
      r(i, s(child)) {
        child[i]->print(out);
      }
      out << ")";
    } else {
      out << "" << var << "";
    }
  }
  void normal() {
    r(i, s(child)) {
      child[i]->normal();
    }
    if (neg) {
      if (op == '*' || op == '+') {
        neg = false;
        op = (op == '*' ? '+' : '*');
        r(i, s(child)) {
          child[i]->neg = !child[i]->neg;
          if (child[i]->neg) {
            child[i]->normal();
          }
        }
      }
    }
    if (op == '*' || op == '+') {
      bool changed = true;
      while (changed) {
        changed = false;
        vector<Tree*> next;
        r(i, s(child)) {
          if (child[i]->op == op) {
            r(j, s(child[i]->child)) {
              next.push_back(child[i]->child[j]);
              changed = true;
            }
            //child.insert(child.begin() + i + 1, all(child[i]->child));
            //child.erase(child.begin() + i);
            //i--;
          } else {
            next.push_back(child[i]);
          }
        }
        if (changed) {
          child = next;
        }
      }
    }
    if (op == '*') {
      r(i, s(child)) {
        if (child[i]->op == '+') {
          vector<Tree*> next;
          r(j, s(child[i]->child)) {
            next.resize(j + 1);
            //next[j] = new Tree;
            next[j] = get_tree();
            //ppn(g_ind);
            next[j]->op = '*';
            r(k, i) {
              next[j]->child.push_back(child[k]);  // s
            }
            next[j]->child.push_back(child[i]->child[j]); // F
            rb(k, i + 1, s(child)) {
              next[j]->child.push_back(child[k]); // s'
            }
          }
          op = '+';
          child = next;
          normal();
          break;
        }
      }
    }
  }
  vector<Tree*> proof(bool* vars) {
    vector<Tree*> res;
    if (op == '+') {
      r(i, s(child)) {
        if (child[i]->eval(vars)) {
          res.push_back(child[i]);
        }
      }
    } else if(eval(vars)) {
      res.push_back(this);
    }
    return res;
  }
  bool eval(bool* vars) {
    bool res;
    if (op == '+') {
      res = false;
      r(i, s(child)) {
        res = res || child[i]->eval(vars);
      }
    } else if (op == '*') {
      res = true;
      r(i, s(child)) {
        res = res && child[i]->eval(vars);
      }
    } else if (neg) {
      res = !vars[int(var)];
    } else {
      res = vars[int(var)];
    }
    return res;
  }
  char op, var;
  bool neg;
  vector<Tree*> child;
};

Tree g_trees[100010];

Tree* get_tree() {
  g_trees[g_ind] = Tree();
  return &g_trees[g_ind++];
}

void parse(Tree** T) {
  Tree* t = *T;
  char c;
  cin >> c;
  if (c >= 'a' && c <= 'z') {
    t->var = c;
  } else if (c == '~') {
    t->neg = !t->neg;
    parse(T);
  } else { // c == '('
    cin >> c;
    t->op = c;
    cin >> c;
    int n = 0;
    while (c != ')') {
      cin.putback(c);
      t->child.resize(n + 1);
      //t->child[n] = new Tree;
      t->child[n] = get_tree();
      parse(&t->child[n]);
      n++;
      cin >> c;
    }
    if (n == 1) {
      *T = t->child[0];
    }
  }
}

void parse_v(vector<char> &v) {
  char c;
  cin >> c; // '('
  cin >> c;
  while (c != ')') {
    v.push_back(c);
    cin >> c;
  }
}
 
int main() {
  char c;
  while (cin >> c) {
    g_ind = 0;
    //ppn(c);
    cin.putback(c);
    //Tree* t = new Tree;
    Tree* t = get_tree();
    //ppn(g_ind);
    parse(&t);
    //t.print(); pl;
    t->normal();
    //t.print(); pl;
    vector<char> ax;
    parse_v(ax);
    /*
    r(i, s(ax)) {
      cout << ax[i] << ' ';
    }
    cout << endl;//*/
    bool vars[256] = {0};
    r(i, s(ax)) {
      vars[int(ax[i])] = true;
    }
    vector<Tree*> Proofs = t->proof(vars);
    vector<string> proofs;
    r(i, s(Proofs)) {
      ostringstream out;
      //ppn(i);
      //Proofs[i]->print(); pl;
      Proofs[i]->print(out);
      //ppn(out.str());
      proofs.push_back(out.str());
    }
    /*
    r(i, s(proofs)) {
      proofs[i].print(); pl;
    }
    pl;//*/
    ll val;
    int cur = 0;
    while (cin >> val && val != 0) {
      //ppn(val);
      if (proofs.empty()) continue;
      for (ll i = 0; i < val; i++) {
        cout << proofs[(cur + i) % s(proofs)] << endl;
      }
      cur += abs(val);
      cur %= s(proofs);
    }
  }
  //ppn(c);
} 

