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

typedef long long ll;
 
class ConvexSequence {
	public:
	long long getMinimum(vector <int> a) {
		long long res = 0;
    vector<int> A(a);
    int n = (int) a.size();
 
    for (ll k = 0; k < n * n; k++) {
      for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n - 1; j++) {
          if (a[i] < (j - i + 1) * a[j] - (j - i) * a[j + 1]) {
            ll na = (a[i] + (j - i) * a[j + 1]) / (j - i + 1);
            res += a[j] - na;
            a[j] = na;
          }
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
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,5,1,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = {3,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,0,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = {854159326, 317144183, 781399725, 287076509, 894967145, 882577367, 174517516, 134415519,
 274494874, 709819883, 59717133, 732212854, 40551288, 232526958, 811785438, 930853743,
 946882902, 321325300, 397702677, 376192501, 599310562, 889156198, 135776890, 882710939,
 823196361, 681959076, 318666702, 94469186, 536320456, 116468376, 530320850, 436708006,
 903344748, 659080120, 774722507, 967315412, 566063635, 43970906, 497687103, 781266213,
 876086123, 366960001, 587364849, 191948103, 172568553, 539762057, 83507466, 71569625,
 686305822, 663789601}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 20178337330LL; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	ConvexSequence ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
