#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, ct = 0, sum = 0;
  cin >> n;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cout << i << " " << n / i << "\n";
      ct++;
      sum += i;
      if (n / i != i) {
        ct++;
        sum += n / i;
      }
    }
  }
  cout << "count of divisors: " << ct << " Sum: " << sum << "\n";
}
// TC -> O(sqrt(n))
