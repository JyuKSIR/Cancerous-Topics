#include <bits/stdc++.h>
using namespace std;

const int mxn = 100000;

int dp[mxn + 1];
// -1 = unknown
//  0 = first player from this state loses
//  1 = first player from this state wins

int fun(int n) { 
  if (/* no move possible / losing base case */) {
    return 0;
  }

  if (dp[n] != -1) return dp[n];

  bool w = 0;

  for (/* each possible move */) {
    int nxt = /* next state */;

    // If opponent loses from nxt,
    // current first player wins from n.
    w |= !fun(nxt);
  }

  return dp[n] = w;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  int n;
  cin >> n;

  if (fun(n)) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }

  return 0;
}
// Both players have the same moves.
// Whoever cannot move loses.
// The goal swaps naturally between players.
