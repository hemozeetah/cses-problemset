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
  for (int i = 0; i < (1 << n); i++) {
    int x = i ^ (i >> 1);
    std::string bs = std::bitset<16>(x).to_string();
    std::cout << bs.substr(16 - n, n) << '\n';
  }
  return 0;
}
