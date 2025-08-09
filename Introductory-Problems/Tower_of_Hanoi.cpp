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
  std::vector<std::pair<int, int>> ans;
  auto solve = [&](auto &&self, int n, int from, int to) -> void {
    if (n == 1) {
      ans.emplace_back(from, to);
      return;
    }
    int other = from ^ to;
    self(self, n - 1, from, other);
    ans.emplace_back(from, to);
    self(self, n - 1, other, to);
  };
  solve(solve, n, 1, 3);
  std::cout << (int)ans.size() << '\n';
  for (auto [from, to] : ans) {
    std::cout << from << ' ' << to << '\n';
  }
  return 0;
}
