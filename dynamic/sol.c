// SollyCB | Sat 24 Aug 20:17:57 +08 2024 |

#include <bits/stdc++.h>

using namespace std;

#define MOD ((long)10e9 + 7)

int main() {

  #if 0
    {
        int x = 6;
        int coins[] = {1,3,4};

        // Minimum number of coins required for the sum
        vector<int> v;
        v.push_back(0);
        for(int i=1; i <= x; ++i) {
            v.push_back(0x7fffffff);
            for(auto c : coins) {
                if (i - c >= 0) {
                    v[i] = min(v[i], v[i-c]+1);
                }
            }
        }
        int min = 0x7fffffff;
        for(auto i : v) {
            min = i < min ? i : min;
        }

        printf("minimum number of coins required for sum: %i\n", v[v.size()-1]);

        // Number of ways to solve the sum
        vector<int> a(v.size());
        a[0] = 1;
        for(int i=1; i <= x; ++i) {
            for(auto c : coins) {
                if (i - c >= 0) {
                    a[i] += a[i-c];
                    a[i] %= MOD;
                }
            }
        }
        printf("number of ways to construct the sum: %i\n", a[x]);

        // longest increasing subsequence
        vector<int> r = {6, 2, 5, 1, 7, 4, 8, 3};
        vector<int> b(r.size());
        vector<int> c(r.size());
        for(int i=0; i < r.size(); ++i) {
            b[i] = 1;
            c[i] = 1;
            for(int j=0; j < i; ++j) {
                if (r[j] < r[i] && b[j]+1 > b[i]) {
                    b[i] = b[j]+1;
                    c[i] = i-j;
                }
            }
        }
        int me = *max_element(b.begin(), b.end());
        int f = distance(b.begin(), max_element(b.begin(), b.end()));
        int m = me-1;
        vector<int> d(me);
        do {
            d[m] = r[f];
            f -= c[f];
            m--;
        } while(b[f] > 1);
        d[m] = r[f];
        printf("longest increasing subsequence %i\n", me);
        printf("numbers in the sequence are: ");
        for(int l : d)
            printf("%i, ", l);
        printf("\n");
    }

    {
        // Longest increasing subsequence O(nLogn);
        //
        // Explaner:
        // Allows the head to become a new value which is smaller but which would still be a valid
        // head for the current longest subsequence (being larger than everything before). Smaller
        // but still valid means that it must return an equal or longer subsequence.
        //
        // It looks funky, because it looks like the algorithm gives a shit about the body of the
        // answer array, but really it only cares about the head. The body is just maintained as
        // sorted as this allows for new heads.
        vector<int> r = {6, 2, 5, 1, 7, 4, 8, 3};
        vector<int> a;
        a.push_back(r[0]);
        for(int i=1; i < r.size(); ++i) {
            if (r[i] > a.back()) {
                a.push_back(r[i]);
            } else {
                *lower_bound(a.begin(), a.end(), r[i]) = r[i];
            }
        }
        printf("Fast longest increasing subsequence %li\n", a.size());
    }
  #endif

    {
      int g[6][6] = {
        {0,0,0,0,0,0},
        {0,3,7,9,2,7},
        {0,9,8,3,5,5},
        {0,1,7,9,8,5},
        {0,3,8,6,4,10},
        {0,6,3,9,7,8},
      };
      int n = 5;

      int s[6][6] = {0};

      for(int i=1; i <= n; ++i) {
        for(int j=1; j <= n; ++j) {
          s[i][j] = max(s[i-1][j], s[i][j-1]) + g[i][j];
        }
      }
      printf("Greatest sum path %i\n", s[5][5]);
    }

    {
      int w[] = {0,1,3,3,5};
      bool v[13] = {0};
      v[0] = 1;
      for(int i=1; i <= 4; ++i) {
        for(int j=12; j >= 0; --j) {
          if (v[j]) {
            v[j+w[i]] = 1;
          }
        }
      }
      printf("Index %i %s be constructed\n", 12, v[12] ? "can" : "cannot");
      printf("Index %i %s be constructed\n", 10, v[10] ? "can" : "cannot");
    }

    return 0;
}
