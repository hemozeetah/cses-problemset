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
  std::vector<std::string> s(n);
  for (std::string &x : s) {
    std::cin >> x;
  }
  std::vector<std::pair<int, int>> q{std::pair(0, 0)};
  std::vector added(n, std::vector<bool>(n));
  std::string ans;
  while (!q.empty()) {
    char mn = 'Z';
    for (const auto &[i, j] : q) {
      mn = std::min(mn, s[i][j]);
    }
    ans += mn;
    std::vector<std::pair<int, int>> nq;
    for (const auto &[i, j] : q) {
      if (s[i][j] == mn) {
        if (i + 1 < n && !added[i + 1][j]) {
          nq.emplace_back(i + 1, j);
          added[i + 1][j] = true;
        }
        if (j + 1 < n && !added[i][j + 1]) {
          nq.emplace_back(i, j + 1);
          added[i][j + 1] = true;
        }
      }
    }
    q = std::move(nq);
  }
  std::cout << ans << '\n';
  return 0;
}
