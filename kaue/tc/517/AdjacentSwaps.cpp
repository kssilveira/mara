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

const int MOD = 1000000007;
 
class AdjacentSwaps {
	public:
	int theCount(vector <int> p) {

    int comb[55][55] = {{0}};
    rep(i, 55) comb[i][0] = comb[i][i] = 1;
    repb(i, 1, 55) repbe(j, 1, i)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;

    int dp[55][55] = {{0}};
    int n = (int) p.size();
    for (int i = n - 1; i >= 0; i--) {
      dp[i][i] = 1;
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = 0;
        int sorted[55];
        for (int k = i; k <= j; k++) sorted[k] = p[k];
        sort(sorted + i, sorted + j + 1);
        for (int k = i; k < j; k++) {
          bool in[55] = {0};
          for (int q = i; q < k; q++) in[sorted[q]] = 1;
          in[sorted[k + 1]] = 1;
          bool ok = 1;
          for (int q = i; q <= k; q++) {
            if(!in[p[q]]) {
              ok = 0;
              break;
            }
          }
          if (ok) {
            long long cur = (((long long)dp[i][k]) * dp[k + 1][j]) % MOD;
            cur = (cur * comb[j - i - 1][k - i]) % MOD;
            dp[i][j] = (dp[i][j] + cur) % MOD;
          }
        }
      }
    }
    return dp[0][n - 1];
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 716743312; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	AdjacentSwaps ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
