// SollyCB | Mon 26 Aug 14:41:47 +08 2024 |

#include <bits/stdc++.h>

using namespace std;
#define dynarr vector

int sum(int *tree, int n, int a, int b)
{
  a += n;
  b += n;
  int s = 0;
  while(a <= b) {
    if (a % 2 == 1) s += tree[a++];
    if (b % 2 == 0) s += tree[b--];
    a /= 2;
    b /= 2;
  }
  return s;
}

void add(int *tree, int n, int k, int x)
{
  k += n;
  tree[k] += x;
  for(k /= 2; k >= 1; k /= 2) {
    tree[k] = tree[2*k] + tree[2*k+1];
  }
}

dynarr<int> segtree(dynarr<int> &a)
{
  int n = a.size();
  if ((n&(n-1)) != 0) {
    n = 1 << (32 - __builtin_clz(n));
  }
  dynarr<int> t(2*n);
  for(int i=0; i < (int)a.size(); ++i) {
    add(t.data(), n, i, a[i]);
  }
  t.resize(t.size()/2);
  return t;
}

int main() {
  dynarr<int> a = {5, 8, 6, 3, 2, 7, 2, 6,};
  dynarr<int> t = segtree(a);
  printf("%i\n", sum(t.data(), t.size(), 2, 7));
  return 0;
}
