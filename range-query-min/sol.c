// SollyCB | Sun 25 Aug 20:32:47 +08 2024 |

#include <bits/stdc++.h>

using namespace std;
#define dynarr vector

int main() {

  int a[] = {1, 3, 4, 8, 6, 1, 4, 2};
  int n = sizeof(a)/sizeof(*a);
  int c = n * ceil(log2(n));
  dynarr<int> v(c);
  dynarr<int> d;
  d.push_back(0);
  for(int i=0; i < n; ++i)
    v[i] = a[i];
  int l = n;
  for(int k=2; k <= n; k *= 2) {
    int i = 0;
    d.push_back(l);
    for(int j=k-1; j < n; ++j,++i) {
      int w = (j - i + 1)/2;
      int s = v[i] < v[i+w-1] ? v[i] : v[i+w-1];
      int t = v[j] < v[i+w] ? v[j] : v[i+w];
      v[l] = s < t ? s : t;
      l++;
    }
  }
  int p[] = {1, 2, 3, 6};
  int q[] = {6, 3, 3, 7};
  int m = sizeof(p)/sizeof(*p);
  dynarr<int> r(m);
  for(int i=0; i < m; ++i) {
    int t = q[i]-p[i]+1;
    int k = (t&(t-1))==0 ? t : 32 - __builtin_clz(t) + 1;
    int x = p[i] + d[__builtin_ctz(k)];
    int y = q[i] + d[__builtin_ctz(k)] - k + 1;
    r[i] = v[x] < v[y] ? v[x] : v[y];
  }

  for(int i=0; i < m; ++i) {
    printf("min in range [%i..%i]: %i\n", p[i], q[i], r[i]);
  }

  return 0;
}
