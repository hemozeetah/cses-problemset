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
  std::vector<int> a(n);
  for (int &e : a) {
    std::cin >> e;
  }
  std::map<int, std::pair<int, int>> pos;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto it = pos.find(x - a[i] - a[j]);
      if (it != pos.end()) {
        const auto &[p, q] = it->second;
        std::cout << p + 1 << ' ' << q + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
        return 0;
      }
    }
    for (int j = 0; j < i; j++) {
      pos[a[i] + a[j]] = std::pair(j, i);
    }
  }
  std::cout << "IMPOSSIBLE\n";
  return 0;
}
