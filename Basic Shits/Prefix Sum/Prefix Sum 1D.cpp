#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q; cin >> n >> q;
  ll a[n + 1]{}, p[n + 1]{};
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    ll sum = p[r] - p[l - 1];
    cout << sum << "\n";
  }
}
