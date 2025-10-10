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
  std::vector<int> c(n);
  std::iota(c.begin(), c.end(), 0);
  for (int i = 0; i < (int)c.size(); i++) {
    if (i & 1) {
      std::cout << c[i] + 1 << " \n"[i + 1 == (int)c.size()];
    } else {
      c.push_back(c[i]);
    }
  }
  return 0;
}
