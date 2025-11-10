#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector dp(n + 1, std::vector<int>(m + 1, INT_MAX));
  int mn = std::min(n, m);
  int mx = std::max(n, m);
  for (int i = 1; i <= mn; i++) {
    dp[i][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j] == INT_MAX) {
        continue;
      }
      for (int k = 1; k < mx; k++) {
        if (i + k <= n && dp[k][j] != INT_MAX) {
          dp[i + k][j] = std::min(dp[i + k][j], dp[i][j] + dp[k][j] + 1);
        }
        if (j + k <= m && dp[i][k] != INT_MAX) {
          dp[i][j + k] = std::min(dp[i][j + k], dp[i][j] + dp[i][k] + 1);
        }
      }
    }
  }
  std::cout << dp[n][m] << '\n';
  return 0;
}
