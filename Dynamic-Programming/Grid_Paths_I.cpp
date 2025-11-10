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
  std::vector<std::string> a(n);
  for (std::string &s : a) {
    std::cin >> s;
  }
  if (a[0][0] == '*' || a[n - 1][n - 1] == '*') {
    std::cout << 0 << '\n';
    return 0;
  }
  std::vector dp(n, std::vector<int>(n));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j + 1 < n && a[i][j + 1] == '.') {
        dp[i][j + 1] += dp[i][j];
        if (dp[i][j + 1] >= M) {
          dp[i][j + 1] -= M;
        }
      }
      if (i + 1 < n && a[i + 1][j] == '.') {
        dp[i + 1][j] += dp[i][j];
        if (dp[i + 1][j] >= M) {
          dp[i + 1][j] -= M;
        }
      }
    }
  }
  std::cout << dp[n - 1][n - 1] << '\n';
  return 0;
}
