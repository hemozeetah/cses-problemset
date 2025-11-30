#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  std::cin >> n >> x;
  std::vector<int> w(n);
  for (int &e : w) {
    std::cin >> e;
  }
  std::vector dp(1 << n, std::pair(INT_MAX, 0));
  dp[0] = std::pair(1, 0);
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & 1 << i) {
        continue;
      }
      auto [rides, weight] = dp[mask];
      if (weight + w[i] <= x) {
        weight += w[i];
      } else {
        rides += 1;
        weight = std::min(weight, w[i]);
      }
      dp[mask ^ 1 << i] = std::min(dp[mask ^ 1 << i], std::pair(rides, weight));
    }
  }
  std::cout << dp.back().first << '\n';
  return 0;
}
