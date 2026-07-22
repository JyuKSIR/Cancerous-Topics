#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);


  

  auto f = [&](ll x) -> bool {
    if (condition) return 1;
    return 0;
  };

  ll l = 1, r = 1e18;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (f(m)) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  // r is the last 1 and l is the first 0
  cout << r << ' ' << l << '\n';

  return 0;
}
