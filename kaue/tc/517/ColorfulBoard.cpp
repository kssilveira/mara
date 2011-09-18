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
 
class ColorfulBoard {
	public:
	int theMin(vector <string> BOARD) {
    int n = (int) BOARD.size(), m = (int) BOARD[0].length();
    char board[55][55];
    rep (i, n) rep(j, m) board[i][j] = BOARD[i][j];
		int res = -1;
    rep(rotation, 2) {
      rep(col, m) {
        int graph[55][55] = {{0}}, degree[55] = {0}, type[55] = {0};
        int cur = n + m;
        bool ok = 1;
        rep(j, m) {
          char color = ' ';
          rep(i, n) {
            if (board[i][j] != board[i][col]) {
              if (color != ' ' && color != board[i][j]) {
                ok = 0;
                break;
              }
              color = board[i][j];
            }
          }
          if (!ok) break;
          if (color == ' ') {
            cur--;
            continue;
          }
          rep(i, n) {
            if (board[i][col] == color) type[i] = 0;
            else if (board[i][j] == board[i][col]) type[i] = 1;
            else type[i] = -1;
          }
          rep(i, n) {
            rep(j, n) {
              if (type[i] == -1 && type[j] == 1) {
                graph[i][j] = 1;
              }
            }
          }
        }
        if (!ok) continue;
        rep(i, n) {
          rep(j, n) {
            degree[j] += graph[i][j];
          }
        }
        int top = 0;
        int stack[55];
        rep(i, n) {
          if (!degree[i]) {
            stack[++top] = i;
          }
        }
        repbe(i, 1, top) {
          rep(j, n) {
            if (graph[stack[i]][j]) {
              degree[j]--;
              if (!degree[j]) {
                stack[++top] = j;
              }
            }
          }
        }
        if (top < n) continue;
        if (res == -1 || cur < res) res = cur;
      }
      swap(n, m);
      char transposed[55][55];
      rep(i, n) {
        rep(j, m) {
          transposed[i][j] = board[j][i];
        }
      }
      rep(i, n) {
        rep(j, m) {
          board[i][j] = transposed[i][j];
        }
      }
    }
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SSS",
 "SRR",
 "SMM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theMin(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, theMin(Arg0)); }
	void test_case_2() { string Arr0[] = {"Ab",
 "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, theMin(Arg0)); }
	void test_case_3() { string Arr0[] = {"iiiii",
 "iwiwi"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, theMin(Arg0)); }
	void test_case_4() { string Arr0[] = {"ffffffffff",
 "xfxxoofoxo",
 "ffffffffff",
 "xfxxoofoxo",
 "ffffffffff",
 "ooxxoofoxo",
 "xfxxoofoxo",
 "xfxxoxfxxo",
 "ffxxofffxo",
 "xfxxoxfxxo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(4, Arg1, theMin(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	ColorfulBoard ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
