#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int M = int(1e9) + 7;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  long long ans = 1;
  while (n--) {
    ans <<= 1;
    if (ans >= M) {
      ans -= M;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
