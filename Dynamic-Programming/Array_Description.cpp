#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int M = 1e9 + 7;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    --x;
  }
  std::vector<int> dp(m);
  if (a[0] == -1) {
    std::fill(dp.begin(), dp.end(), 1);
  } else {
    dp[a[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    std::vector<int> ndp(m);
    if (a[i] != -1) {
      for (int k = std::max(a[i] - 1, 0); k < std::min(a[i] + 2, m); k++) {
        ndp[a[i]] += dp[k];
        if (ndp[a[i]] >= M) {
          ndp[a[i]] -= M;
        }
      }
    } else {
      for (int j = 0; j < m; j++) {
        for (int k = std::max(j - 1, 0); k < std::min(j + 2, m); k++) {
          ndp[j] += dp[k];
          if (ndp[j] >= M) {
            ndp[j] -= M;
          }
        }
      }
    }
    std::swap(dp, ndp);
  }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    ans += dp[j];
    if (ans >= M) {
      ans -= M;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
