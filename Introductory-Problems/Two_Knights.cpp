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
  int n;
  std::cin >> n;
  for (int k = 1; k <= n; k++) {
    long long places = square(k);
    long long ways = places * (places - 1 - 8);
    ways += 4 * 4 * k - 4;
    ways += 4 * 2 * (k - 2) + 4;
    ways /= 2;
    std::cout << ways << '\n';
  }
  return 0;
}
