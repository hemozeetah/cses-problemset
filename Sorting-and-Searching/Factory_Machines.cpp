#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, t;
  std::cin >> n >> t;
  std::vector<int> k(n);
  for (int &x : k) {
    std::cin >> x;
  }
  auto target_achievalble = [&](int64_t time) -> bool {
    int64_t cnt = 0;
    for (const int &x : k) {
      cnt += time / x;
      if (cnt >= t) {
        return true;
      }
    }
    return false;
  };
  int64_t l = 0, r = 1e18L;
  while (l <= r) {
    int64_t m = (l + r) >> 1;
    if (target_achievalble(m)) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  std::cout << l << '\n';
  return 0;
}
