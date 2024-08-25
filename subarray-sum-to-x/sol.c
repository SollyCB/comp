#include <bits/stdc++.h>

using namespace std;

int main() {
    {
        int x = 8;
        int v[] = {1, 3, 2, 5, 1, 1, 2, 3};
        int n = sizeof(v)/sizeof(*v);
        int a = 0;
        int b = 0;
        int s = v[0];
        for(int i=1; i < n-1; ++i) {
            if (a > b) {
                if (s + v[a+1] <= x) {
                    a++;
                    s += v[a];
                }
            } else {
                if (s + v[b+1] <= x) {
                    b++;
                    s += v[b];
                }
            }
            if (s == x)
                break;
            if (a < b) a++;
            else b++;
        }
        printf("Two sum: %i, %i, %i\n", s, a, b);
    }
    {
      // @Note If all values must be unique, then this implementation
      // will need more checks, but this should be pretty trivial. Just
      // just check that i != j, and if a.find() == v[i] || == v[j], check that
      // this value appears more than once in the array (e.g. use unordered_map
      // and store counts with inserted values).
      int x = 12;
      int v[] = {1, 4, 5, 6, 7, 9, 9, 10};
      int n = sizeof(v) / sizeof(*v);

      unordered_set<int> a;
      for (int i = 0; i < n; ++i)
        a.insert(v[i]);
      bool e = 0;
      int i, j;
      for (i = 0; i < n && !e; ++i)
        for (j = 0; j < n && !e; ++j) {
          if (a.find(x - (v[i] + v[j])) != a.end())
            e = 1;
        }
        printf("Three sum: %i, %i, %i\n", v[i], v[j], x - (v[i]+v[j]));
    }
    return 0;
}
