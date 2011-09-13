#include <cstdio>
#include <iostream>
#include <vector>
using namespace std; 
typedef int* It;

int temp[(int)(1e5 + 1)];
int x[(int)(1e5 + 1)];

int merge(It begin, It middle, It end) {
  It left = begin, right = middle;
  int res = 0;
  int n = 0;
  while (left != middle && right != end) {
    if (*left <= *right) {  // never equal in this problem
      temp[n++] = *(left++);
    } else {
      res += middle - left;
      temp[n++] = *(right++);
    }
  }
  while (left != middle) {
    temp[n++] = *(left++);
  }
  while (right != end) {
    temp[n++] = *(right++);
  }
  for (int i = 0; i < n; ++i) {
    begin[i] = temp[i];
  }
  return res;
}

int msort(It begin, It end) {
  if (begin == end || begin + 1 == end) {
    return 0;
  }
  It middle = begin + (end - begin) / 2;
  return msort(begin, middle) + msort(middle, end) +
    merge(begin, middle, end);
}

int main() {
  int n;
  scanf("%i", &n);
  while (n != 0) {
    for (int i = 0; i < n; i++) {
      scanf("%i", &x[i]);
    }

    int res = msort(x, x + n);

    /*
    for (int i = 0; i < (int) x.size(); i++) {
      cout << x[i] << " ";
    }
    cout << endl;//*/

    cout << (res % 2 ? "Marcelo" : "Carlos") << endl;

    scanf("%i", &n);
  }
}
