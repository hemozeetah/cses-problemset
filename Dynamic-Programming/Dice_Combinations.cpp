#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int M = 1e9 + 7;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int d = 1; d <= 6; d++) {
      if (i + d > n) {
        break;
      }
      dp[i + d] += dp[i];
      if (dp[i + d] >= M) {
        dp[i + d] -= M;
      }
    }
  }
  std::cout << dp[n] << '\n';
  return 0;
}
