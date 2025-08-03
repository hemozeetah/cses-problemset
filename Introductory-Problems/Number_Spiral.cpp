#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

long long square(long long x) {
  return x * x;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int y, x;
    std::cin >> y >> x;
    if (std::max(y, x) & 1) {
      std::swap(y, x);
    }
    long long block = square(std::max(y, x));
    std::cout << block - (x - 1) - (std::max(y, x) - y) << '\n';
  }
  return 0;
}
