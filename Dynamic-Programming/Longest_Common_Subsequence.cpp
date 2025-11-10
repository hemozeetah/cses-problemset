#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::vector<int> b(m);
  for (int &x : b) {
    std::cin >> x;
  }
  std::vector dp(n + 1, std::vector<int>(m + 1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i < n && j < m && a[i] == b[j]) {
        dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      if (i < n) {
        dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
      }
      if (j < m) {
        dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j]);
      }
    }
  }
  std::vector<int> v;
  int i = n, j = m;
  do {
    if (i > 0 && j > 0 && a[i - 1] == b[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
      v.push_back(i - 1);
      i -= 1;
      j -= 1;
    } else if (i > 0 && dp[i][j] == dp[i - 1][j]) {
      i -= 1;
    } else {
      j -= 1;
    }
  } while (i != 0 || j != 0);
  assert((int)v.size() == dp[n][m]);
  std::reverse(v.begin(), v.end());
  std::cout << v.size() << '\n';
  for (const int &i : v) {
    std::cout << a[i] << " \n"[i == v.back()];
  }
  return 0;
}
