// SollyCB | Sun 25 Aug 18:37:53 +08 2024 |

#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[] = {2, 1, 4, 5, 3, 4, 1, 2};
  int n = sizeof(a)/sizeof(*a);
  int s = 4;
  deque<int> d;
  d.push_back(a[0]);
  for(int i=1; i < n; ++i) {
    while(!d.empty() && d.back() > a[i]) {
      d.pop_back();
    }
    d.push_back(a[i]);
    printf("win min %i : win max %i\n", d.front(), d.back());
    if (i > s-1 && d.front() == a[i-(s-1)])
      d.pop_front();
  }
  return 0;
}
