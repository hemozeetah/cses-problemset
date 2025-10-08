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
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  long long ans = 0;
  std::map<int, int> pos;
  int l = -1;
  for (int r = 0; r < n; r++) {
    auto it = pos.find(x[r]);
    if (it != pos.end()) {
      l = std::max(l, it->second);
    }
    ans += r - l;
    pos[x[r]] = r;
  }
  std::cout << ans << '\n';
  return 0;
}
