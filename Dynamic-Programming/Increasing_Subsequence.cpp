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
  std::vector<int> dp;
  for (const int &e : x) {
    auto it = lower_bound(dp.begin(), dp.end(), e);
    if (it == dp.end()) {
      dp.push_back(e);
    } else {
      *it = e;
    }
  }
  std::cout << dp.size() << '\n';
  return 0;
}
