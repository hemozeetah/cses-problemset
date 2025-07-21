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
  long long ans = (long long)(n + 1) * n / 2;
  std::map<int, std::pair<int, int>> appeared;
  for (int i = 0; i < n; i++) {
    auto it = appeared.find(x[i]);
    if (it != appeared.end()) {
      auto [j, cnt] = it->second;
      ans -= (long long)(n - i) * cnt;
      appeared[x[i]] = std::pair(i, i - j);
    } else {
      appeared[x[i]] = std::pair(i, i + 1);
    }
  }
  std::cout << ans << '\n';
  return 0;
}
