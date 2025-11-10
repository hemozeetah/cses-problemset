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
  std::vector<int> h(n);
  for (int &e : h) {
    std::cin >> e;
  }
  std::vector<int> s(n);
  for (int &e : s) {
    std::cin >> e;
  }
  std::vector<int> dp(x + 1);
  for (int i = 0; i < n; i++) {
    std::vector<int> ndp = dp;
    for (int c = 0; c < x; c++) {
      ndp[c + 1] = std::max(ndp[c + 1], ndp[c]);
      if (c + h[i] <= x) {
        ndp[c + h[i]] = std::max(ndp[c + h[i]], dp[c] + s[i]);
      }
    }
    std::swap(dp, ndp);
  }
  std::cout << dp[x] << '\n';
  return 0;
}
