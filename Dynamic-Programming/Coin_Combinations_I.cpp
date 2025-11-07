#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int M = 1e9 + 7;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  std::cin >> n >> x;
  std::vector<int> c(n);
  for (int &e : c) {
    std::cin >> e;
  }
  std::vector<int> dp(x + 1);
  dp[0] = 1;
  for (int s = 0; s < x; s++) {
    for (int i = 0; i < n; i++) {
      if (s + c[i] <= x) {
        dp[s + c[i]] += dp[s];
        if (dp[s + c[i]] >= M) {
          dp[s + c[i]] -= M;
        }
      }
    }
  }
  std::cout << dp[x] << '\n';
  return 0;
}
