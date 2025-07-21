#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  long long n;
  std::cin >> n;
  while (true) {
    std::cout << n << " \n"[n == 1];
    if (n == 1) {
      break;
    }
    n = ((n & 1) == 1 ? n * 3 + 1 : n / 2);
  }
  return 0;
}
