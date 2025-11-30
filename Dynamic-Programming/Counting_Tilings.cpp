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
  std::vector<std::vector<int>> next_masks(1 << n);
  auto generate = [&](auto &&self, int mask, int i = 0, int next_mask = 0) -> void {
    if (i == n) {
      next_masks[mask].push_back(next_mask);
      return;
    }
    if (mask & 1 << i) {
      self(self, mask, i + 1, next_mask);
    } else {
      self(self, mask, i + 1, next_mask | 1 << i);
      if (i != n - 1 && (mask & 1 << (i + 1)) == 0) {
        self(self, mask, i + 2, next_mask);
      }
    }
  };
  for (int mask = 0; mask < (1 << n); mask++) {
    generate(generate, mask);
  }
  std::vector<int> dp(1 << n);
  dp[0] = 1;
  for (int i = 0; i < m; i++) {
  std::vector<int> ndp(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
      for (const int &nmask : next_masks[mask]) {
        ndp[nmask] += dp[mask];
        if (ndp[nmask] >= M) {
          ndp[nmask] -= M;
        }
      }
    }
    dp = std::move(ndp);
  }
  std::cout << dp[0] << '\n';
  return 0;
}
