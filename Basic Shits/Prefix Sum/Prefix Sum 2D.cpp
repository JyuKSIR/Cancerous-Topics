#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q; 
  cin >> n >> m >> q;
  // 1-indexed
  vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
  vector<vector<ll>> p(n + 1, vector<ll>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
    }
  }
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll sum = p[r2][c2] - p[r1 - 1][c2] - 
             p[r2][c1 - 1] + p[r1 - 1][c1 - 1];
    cout << sum << "\n";
  }
}
