#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int x, n;
  std::cin >> x >> n;
  std::set<std::pair<int, int>> ran;
  std::multiset<int> len;
  ran.insert(std::pair(0, x));
  len.insert(x);
  for (int i = 0; i < n; i++) {
    int p;
    std::cin >> p;
    auto it = ran.upper_bound(std::pair(p, -1));
    assert(it != ran.begin());
    it = std::prev(it);
    auto [l, r] = *it;
    ran.erase(it);
    ran.insert(std::pair(l, p));
    ran.insert(std::pair(p, r));
    auto it2 = len.find(r - l);
    assert(it2 != len.end());
    len.erase(it2);
    len.insert(p - l);
    len.insert(r - p);
    int ans = *len.rbegin();
    std::cout << ans << " \n"[i == n - 1];
  }
  return 0;
}
