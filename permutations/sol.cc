#include <bits/stdc++.h>

using namespace std;

#define n 3
vector<int> p;
int a[n] = {0};

void search() {
    if (p.size() == n) {
        for(auto x : p) {
            printf("%i, ", x);
        }
        printf("\n");
    } else {
        for(int i=0; i < n; ++i) {
            if (a[i]) continue;
            a[i] = 1;
            p.push_back(i);
            search();
            a[i] = 0;
            p.pop_back();
        }
    }
}

int main() {
    search();
    p.clear();

    printf("------------------------------------------------------------------------------------------\n");

    for(int i=0; i < n; ++i)
        p.push_back(i);
    do {
        for(auto x : p)
            printf("%i, ", x);
        printf("\n");
    } while(next_permutation(p.begin(), p.end()));

    return 0;
}
