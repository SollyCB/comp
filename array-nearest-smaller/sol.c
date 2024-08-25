// SollyCB | Sun 25 Aug 18:04:11 +08 2024 |

#include <bits/stdc++.h>

using namespace std;

int main() {

  int a[] = {1, 3, 4, 2, 5, 3, 4, 2};
  int n = sizeof(a)/sizeof(*a);
  stack<int> s;
  s.push(a[0]);
  vector<int> v;
  v.push_back(0);
  for(int i=1; i < n; ++i) {
    int x = a[i];
      while(!s.empty() && s.top() >= x) {
        s.pop();
      }
      if (s.empty()) {
        cout << "FAIL\n";
        return 0;
      }
      v.push_back(s.top());
      s.push(x);
  }
  // for(int x : v)
  //   printf("%i, ", x);
  // printf("\n");
  printf("Nearest smallest for index %i (%i) is %i\n", 4, a[4], v[4]);
  printf("Nearest smallest for index %i (%i) is %i\n", 2, a[2], v[2]);
  printf("Nearest smallest for index %i (%i) is %i\n", 6, a[6], v[6]);

  return 0;
}
