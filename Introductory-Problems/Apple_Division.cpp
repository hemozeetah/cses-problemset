#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const long long INF = 1e18L;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
  }
  long long ans = INF;
  for (int b = 0; b < (1 << n); b++) {
    long long sum[2] = {};
    for (int i = 0; i < n; i++) {
      sum[(b >> i) & 1] += p[i];
    }
    ans = std::min(ans, std::abs(sum[0] - sum[1]));
  }
  std::cout << ans << '\n';
  return 0;
}
