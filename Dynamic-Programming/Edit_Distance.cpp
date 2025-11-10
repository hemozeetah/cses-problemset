#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  std::string t;
  std::cin >> t;
  int n = (int)s.size();
  int m = (int)t.size();
  std::vector dp(n + 1, std::vector<int>(m + 1, INT_MAX));
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i < n && j < m) {
        dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + (s[i] != t[j]));
      }
      if (i < n) {
        dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + 1);
      }
      if (j < m) {
        dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j] + 1);
      }
    }
  }
  std::cout << dp[n][m] << '\n';
  return 0;
}
