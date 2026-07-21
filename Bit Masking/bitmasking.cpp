#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll sz = (1 << n);
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        // if the bit is set
      } else {
        // if the bit is not set
      }
    }
  }
}
