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
  std::vector<int> a(n - 1);
  for (int &x : a) {
    std::cin >> x;
  }
  long long sum = std::accumulate(a.begin(), a.end(), 0LL);
  std::cout << (long long)n * (n + 1) / 2 - sum << '\n';
  return 0;
}
