#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const long long INF = 1LL << 60;

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  long long ans = -INF;
  long long ps = 0;
  for (const int &x : a) {
    ps = std::max<long long>(x, ps + x);
    ans = std::max(ans, ps);
  }
  std::cout << ans << '\n';
  return 0;
}
