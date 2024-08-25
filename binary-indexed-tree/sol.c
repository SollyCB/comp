// SollyCB | Mon 26 Aug 03:10:18 +08 2024 |

#include <bits/stdc++.h>

using namespace std;
#define dynarr vector

int sum(int *tree, int k) {
  k += 1;
  int s = 0;
  while(k >= 1) {
    s += tree[k-1];
    k -= k & -k;
  }
  return s;
}

void add(int *tree, int l, int k, int x) {
  k += 1;
  while(k <= l) {
    tree[k-1] += x;
    k += k&-k;
  }
}

int main() {

  dynarr<int> a = {1, 3, 4, 8, 6, 1, 4, 2,};
  dynarr<int> v(a.size());
  for(int i=0; i < (int)a.size(); ++i) {
    add(v.data(), v.size(), i, a[i]);
  }
  for(int i=0; i < (int)v.size(); ++i) {
    printf("%i, ", v[i]);
  }
  printf("\n");

  dynarr<int> b = {1,2,3,4};
  for(int i=0; i < (int)b.size(); ++i) {
    add(v.data(), v.size(), i, b[i]);
  }
  for(int i=0; i < (int)v.size(); ++i) {
    printf("%i, ", v[i]);
  }
  printf("\n");

  return 0;
}
