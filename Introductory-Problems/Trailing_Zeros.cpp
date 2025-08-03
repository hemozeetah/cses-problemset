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
  int ans = 0;
  while (n / 5 != 0) {
    ans += n / 5;
    n /= 5;
  }
  std::cout << ans << '\n';
  return 0;
}
