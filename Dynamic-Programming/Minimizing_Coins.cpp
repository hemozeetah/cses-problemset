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
  std::vector<int> c(n);
  for (int &e : c) {
    std::cin >> e;
  }
  std::vector<int> dp(x + 1, INT_MAX);
  dp[0] = 0;
  for (int s = 0; s < x; s++) {
    if (dp[s] == INT_MAX) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (s + c[i] <= x) {
        dp[s + c[i]] = std::min(dp[s + c[i]], dp[s] + 1);
      }
    }
  }
  std::cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
  return 0;
}
