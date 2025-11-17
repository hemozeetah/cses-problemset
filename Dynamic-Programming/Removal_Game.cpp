#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  std::vector dp(n, std::vector<int64_t>(n, INT64_MIN));
  for (int i = 0; i < n; i++) {
    dp[i][i] = x[i];
  }
  for (int l = n - 1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l + 1 <= r) {
        dp[l][r] = std::max(dp[l][r], x[l] - dp[l + 1][r]);
      }
      if (l <= r - 1) {
        dp[l][r] = std::max(dp[l][r], x[r] - dp[l][r - 1]);
      }
    }
  }
  int64_t d = dp[0][n - 1];
  int64_t s = std::accumulate(x.begin(), x.end(), 0LL);
  int64_t ans = (s + d) / 2;
  std::cout << ans << '\n';
  return 0;
}
