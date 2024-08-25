#include <bits/stdc++.h>

using namespace std;

int main() {

  int tt;
  cin >> tt;

  while(tt--) {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(),a.end());
    int r = 0;
    for(int i=n-1; i > 0; i -= 2) {
      if (k >= a[i] - a[i-1]) {
        k -= a[i] - a[i-1];
        a[i-1] = a[i];
      } else {
        a[i-1] += k;
        k = 0;
      }
      r += a[i]-a[i-1];
    }
    if (n%2)
      r += a[0];
    cout << r << '\n';
  }

  return 0;
}
