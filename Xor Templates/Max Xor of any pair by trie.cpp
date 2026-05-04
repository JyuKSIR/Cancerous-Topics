#include <bits/stdc++.h>
using namespace std;

struct Trie {
  vector<array<int, 2>> t;
  Trie() {
    t.push_back({-1, -1});
  }
  void insert(int x) {
    int u = 0;
    for (int i = 30; i >= 0; i--) {
      int b = (x >> i) & 1;
      if (t[u][b] == -1) {
        t[u][b] = t.size();
        t.push_back({-1, -1});
      }
      u = t[u][b];
    }
  }

  int query(int x) {
    int u = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--) {
      int b = (x >> i) & 1;
      int want = b ^ 1;
      if (t[u][want] != -1) {
        res |= (1 << i);
        u = t[u][want];
      } else {
        u = t[u][b];
      }
    }
    return res;
  }
};

int maxXorPair(vector<int>& a) {
  int n = a.size();
  if (n < 2) {
    return 0;
  }
  Trie tr;
  tr.insert(a[0]);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, tr.query(a[i]));
    tr.insert(a[i]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << maxXorPair(a) << '\n';
  return 0;
}
TC : O(n)
