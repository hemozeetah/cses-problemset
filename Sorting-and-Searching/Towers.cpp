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
  std::vector<int> k(n);
  for (int &e : k) {
    std::cin >> e;
  }
  std::multiset<int> ms;
  for (const int &e : k) {
    auto it = ms.upper_bound(e);
    if (it != ms.end()) {
      ms.erase(it);
    }
    ms.insert(e);
  }
  int ans = ms.size();
  std::cout << ans << '\n';
  return 0;
}
