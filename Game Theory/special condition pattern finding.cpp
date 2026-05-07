#include <bits/stdc++.h>
using namespace std;

const int mxa = 1000;
const int mxb = 1000;

int dp[mxa + 1][mxb + 1][2];

// -1 = unknown
//  0 = Alice loses from this state
//  1 = Alice wins from this state
//
// t = 0 -> Alice's turn
// t = 1 -> Bob's turn

int fun(int a, int b, int t) {
  /*
      Losing condition for Alice.

      Example:
      If Bob wins when some condition becomes true,
      then return 0 here.

      Example:
      if (3 * a == 2 * b) return 0;
  */

  if (/* Bob winning condition / special condition */) {
    return 0;
  }

  /*
      Winning condition for Alice.

      Example:
      If the game ends and Bob did not already win,
      Alice wins.

      Example:
      if (a == 0 && b == 1) return 1;
  */

  if (/* Alice winning / game ending condition */) {
    return 1;
  }

  if (dp[a][b][t] != -1) return dp[a][b][t];

  if (t == 0) {
    /*
        Alice's turn.

        Alice wants to find at least one move
        that keeps her winning.

        So we use OR.
    */

    bool w = 0;

    if (/* move 1 possible */) {
      w |= fun(/* next_a */, /* next_b */, 1);
    }

    if (/* move 2 possible */) {
      w |= fun(/* next_a */, /* next_b */, 1);
    }

    if (/* move 3 possible */) {
      w |= fun(/* next_a */, /* next_b */, 1);
    }

    return dp[a][b][t] = w;
  } else {
    /*
        Bob's turn.

        Bob wants Alice to lose.

        Alice wins only if all Bob's moves
        still lead to Alice winning.

        So we use AND.
    */

    bool w = 1;

    if (/* move 1 possible */) {
      w &= fun(/* next_a */, /* next_b */, 0);
    }

    if (/* move 2 possible */) {
      w &= fun(/* next_a */, /* next_b */, 0);
    }

    if (/* move 3 possible */) {
      w &= fun(/* next_a */, /* next_b */, 0);
    }

    return dp[a][b][t] = w;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  /*
      Pattern finding part.

      Change LIMIT_A and LIMIT_B depending on what you want to observe.
      Usually 20, 30, 50, or 100 is enough to see the pattern.
  */

  int LIMIT_A = 50;
  int LIMIT_B = 50;

  for (int i = 1; i <= LIMIT_A; i++) {
    for (int j = 1; j <= LIMIT_B; j++) {
      if (fun(i, j, 0)) {
        cout << i << " " << j << " A\n";
      } else {
        cout << i << " " << j << " B\n";
      }
    }
  }
}

// Alice starts.
// Alice wants to force her own win.
// Bob wants to force Alice's loss.
// The game has special winning/losing conditions.
