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
  std::vector<int> dp(n + 1, INT_MAX);
  dp[n] = 0;
  for (int i = n; i > 0; i--) {
    if (dp[i] == INT_MAX) {
      continue;
    }
    int j = i;
    while (j != 0) {
      int k = j % 10;
      dp[i - k] = std::min(dp[i - k], dp[i] + 1);
      j /= 10;
    }
  }
  std::cout << dp[0] << '\n';
  return 0;
}
