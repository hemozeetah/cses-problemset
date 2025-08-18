#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  std::cin >> q;
  while (q--) {
    long long k;
    std::cin >> k;
    int len = 1;
    long long p10 = 1;
    while (k > len * 9 * p10) {
      k -= len * 9 * p10;
      len += 1;
      p10 *= 10;
    }
    long long skip = (k - 1) / len;
    k -= skip * len;
    long long number = p10 + skip;
    char digit = std::to_string(number)[k - 1];
    std::cout << digit << '\n';
  }
  return 0;
}
