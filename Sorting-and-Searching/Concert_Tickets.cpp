#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> h(n);
  for (int &x : h) {
    std::cin >> x;
  }
  std::vector<int> t(m);
  for (int &x : t) {
    std::cin >> x;
  }
  std::multiset ms(h.begin(), h.end());
  for (const int &x : t) {
    auto it = ms.upper_bound(x);
    if (it != ms.begin()) {
      it--;
      std::cout << *it << '\n';
      ms.erase(it);
    } else {
      std::cout << -1 << '\n';
    }
  }
  return 0;
}
