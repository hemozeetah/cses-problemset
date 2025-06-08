#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::map<int, int> pos;
  for (int i = 0; i < n; i++) {
    auto it = pos.find(x - a[i]);
    if (it != pos.end()) {
      std::cout << it->second + 1 << ' ' << i + 1 << '\n';
      return 0;
    }
    pos[a[i]] = i;
  }
  std::cout << "IMPOSSIBLE\n";
  return 0;
}
