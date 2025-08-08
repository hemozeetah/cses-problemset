#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << (a / 2 <= b && b <= 2 * a && (2 * a - b) % 3 == 0 ? "YES\n" : "NO\n");
  }
  return 0;
}
