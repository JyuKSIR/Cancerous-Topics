#include <bits/stdc++.h>
using namespace std;

const int mxa = 1000;
const int mxb = 1000;

int dp[mxa + 1][mxb + 1];
// -1 = unknown
//  0 = first player from this state loses
//  1 = first player from this state wins

int fun(int a, int b) {
  if (/* no move possible / losing base case */) {
    return 1; // return 0 have to understand it
  }

  if (dp[a][b] != -1) return dp[a][b];

  bool w = 0;

  if (/* move 1 possible */) {
    w |= !fun(/* next_a */, /* next_b */);
  }

  if (/* move 2 possible */) {
    w |= !fun(/* next_a */, /* next_b */);
  }

  return dp[a][b] = w;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  int a, b;
  cin >> a >> b;

  if (fun(a, b)) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }

  return 0;
}
