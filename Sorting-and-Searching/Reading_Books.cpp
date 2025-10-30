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
  std::vector<int> t(n);
  for (int &x : t) {
    std::cin >> x;
  }
  int64_t s = std::accumulate(t.begin(), t.end(), 0LL);
  int mx = *std::max_element(t.begin(), t.end());
  std::cout << std::max<int64_t>(s, 2 * mx) << '\n';
  return 0;
}
