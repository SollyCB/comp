#include <bits/stdc++.h>

using namespace std;

int n = 3;
vector<int> s;
vector<int> r;

#if 0
void search(int k) {
    if (k == n) {
        if (!s.size())
            printf("EMPTY SET");
        for(auto x : s)
            printf("%i, ", x);
        printf("\n");
    } else {
        search(k+1);
        s.push_back(k);
        search(k+1);
        s.pop_back();
    }
}
#else
void search(int k) {
    vector<int> v;
    for(int i=0; i < (1<<n); ++i) {
        v.clear();
        for(int j=0; j < n; ++j) {
            if (i & (1<<j)) v.push_back(j);
        }
        if (!v.size())
            printf("EMPTY SET");
        for(int j=0; j < v.size(); ++j)
            printf("%i, ", v[j]);
        printf("\n");
    }
}
#endif

int main() {
    // generate all subsets of 0..n
    search(0);
    printf("\n");
    return 0;
}
