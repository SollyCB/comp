// SollyCB | Mon 26 Aug 14:41:47 +08 2024 |

#include <bits/stdc++.h>
#define dynarr vector

using namespace std;

int sum(dynarr<int> &tree, int a, int b)
{
  a += tree.size();
  b += tree.size();
  int s = 0;
  while(a <= b) {
    if (a % 2 == 1) {
      s += tree[a++];
    }
    if (b % 2 == 0) {
      s += tree[b--];
    }
    a /= 2;
    b /= 2;
  }
  return s;
}

int min(dynarr<int> &tree, int a, int b)
{
  a += tree.size();
  b += tree.size();
  int m = 0x7fffffff;
  while(a <= b) {
    if (a % 2 == 1) m = tree[a++] < m ? tree[a-1] : m;
    if (b % 2 == 0) m = tree[b--] < m ? tree[b+1] : m;
    a /= 2;
    b /= 2;
  }
  return m;
}

void add(dynarr<int> &tree, int k, int x)
{
  k += tree.size();
  tree[k] += x;
  for(k /= 2; k >= 1; k /= 2) {
    tree[k] = tree[2*k] + tree[2*k+1];
  }
}

dynarr<int> segtree_min(dynarr<int> &a)
{
  int n = a.size();
  if ((n&(n-1)) != 0) {
    n = 1 << (32 - __builtin_clz(n));
  }
  dynarr<int> t(2*n);
  memcpy(t.data() + n, a.data(), 4 * a.size());
  for(int i=0; i < (int)a.size(); ++i) {
    int k = n+i;
    t[k] = a[i];
    for(k /= 2; k >= 1; k /= 2) {
      t[k] = t[2*k] < t[2*k+1] ? t[2*k] : t[2*k+1];
    }
  }
  t.resize(t.size()/2);
  return t;
}

dynarr<int> segtree_sum(dynarr<int> &a)
{
  int n = a.size();
  if ((n&(n-1)) != 0) {
    n = 1 << (32 - __builtin_clz(n));
  }
  dynarr<int> t(2*n);
  t.resize(t.size()/2);
  for(int i=0; i < (int)a.size(); ++i) {
    add(t, i, a[i]);
  }
  return t;
}

int main() {
  {
    printf("-------------------------------------\n");
    printf("sum queries with segtree\n\n");
    dynarr<int> a = {5, 8, 6, 3, 2, 7, 2, 6,};
    printf("original array: ");
    for(int x : a)
      printf("%i, ", x);
    printf("\n");
    dynarr<int> t = segtree_sum(a);
    printf("segtree: ");
    for(int i=0; i < (int)t.size() * 2; ++i)
      printf("%i, ", t[i]);
    printf("\nsum in range 2, 7; %i\n", sum(t, 2, 7));
  } {
    printf("\n-------------------------------------\n");
    printf("min queries with segtree\n\n");
    dynarr<int> a = {5, 8, 6, 3, 1, 7, 2, 6,};
    printf("original array: ");
    for(int x : a)
      printf("%i, ", x);
    printf("\n");
    dynarr<int> t = segtree_min(a);
    printf("segtree: ");
    for(int i=0; i < (int)t.size() * 2; ++i)
      printf("%i, ", t[i]);
    printf("\nmin in range 0, 3:%i\n", min(t, 0, 3));
  }

  // update ranges in original array using segtree + difference array
  {
    printf("\n-------------------------------------\n");
    printf("range updates and value queries with segtree\n\n");
    dynarr<int> a = {3, 3, 1, 1, 1, 5, 2, 2,};
    printf("original array: ");
    for(int x : a)
      printf("%i, ", x);
    printf("\n");
    dynarr<int> b(a.size());
    b[0] = a[0];
    for(int i=1; i < (int)a.size(); ++i) {
      b[i] = a[i] - a[i-1];
    }
    dynarr<int> t = segtree_sum(b);
    printf("segtree: ");
    for(int i=0; i < (int)t.size() * 2; ++i)
      printf("%i, ", t[i]);
    printf("\n");
    printf("value at index 4, 5, 6: %i, %i, %i\n", sum(t, 0, 4), sum(t, 0, 5), sum(t, 0, 6));
    printf("\n");
    int p = 4; int q = 6; int x = 1;
    add(t, p,    x);
    add(t, q+1, -x);
    printf("add %i to range %i, %i\n", x, p, q);
    printf("segtree: ");
    for(int i=0; i < (int)t.size() * 2; ++i)
      printf("%i, ", t[i]);
    printf("\n");
    printf("value at index 4, 5, 6: %i, %i, %i\n", sum(t, 0, 4), sum(t, 0, 5), sum(t, 0, 6));
  }

  return 0;
}
