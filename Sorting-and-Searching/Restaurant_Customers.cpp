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
  std::vector<std::pair<int, bool>> a(2 * n);
  for (int i = 0; i < n; i++) {
    int l, r;
    std::cin >> l >> r;
    a[i << 1] = std::pair(l, true);
    a[i << 1 | 1] = std::pair(r, false);
  }
  std::sort(a.begin(), a.end());
  int ans = 0, cnt = 0;
  for (auto [_, f] : a) {
    cnt += (f ? 1 : -1);
    ans = std::max(ans, cnt);
  }
  std::cout << ans << '\n';
  return 0;
}
