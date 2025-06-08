#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    std::cin >> x >> y;
  }
  std::sort(a.begin(), a.end());
  std::vector<std::pair<int, int>> b;
  for (const auto &[x, y] : a) {
    if (b.empty() || b.back().second <= x) {
       b.emplace_back(x, y);
    } else if (b.back().second > y) {
      b.back() = std::pair(x, y);
    }
  }
  int ans = b.size();
  std::cout << ans << '\n';
  return 0;
}
