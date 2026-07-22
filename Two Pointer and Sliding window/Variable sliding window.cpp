#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = 0, ans = 0 ;
  while (r < n) {
    while (invalid condition) {
      remove a[l]
      l++;
    }
    add a[r]
    ans = max(ans, r - l + 1);
    r++;
  }
  cout << ans;
}
