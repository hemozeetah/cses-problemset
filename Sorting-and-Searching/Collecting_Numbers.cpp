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
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j) { return x[i] < x[j]; });
  int ans = 1;
  for (int i = 0; i + 1 < n; i++) {
    ans += (ord[i + 1] < ord[i]);
  }
  std::cout << ans << '\n';
  return 0;
}
