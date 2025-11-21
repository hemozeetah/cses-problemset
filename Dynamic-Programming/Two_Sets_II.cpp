#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int M = 1e9 + 7;

template <typename T>
constexpr T inverse(T a, T m) {
  T u = 0, v = 1;
  T b = m;
  while (a != 0) {
    T t = b / a;
    b -= t * a; std::swap(a, b);
    u -= t * v; std::swap(u, v);
  }
  assert(b == 1);
  return (u < 0 ? u + m : u);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int sum = n * (n + 1) / 2;
  if (sum & 1) {
    std::cout << 0 << '\n';
    return 0;
  }
  std::vector<int> dp(sum / 2 + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    auto ndp = dp;
    for (int s = 0; s < sum / 2; s++) {
      if (s + (i + 1) <= sum / 2) {
        ndp[s + (i + 1)] += dp[s];
        if (ndp[s + (i + 1)] >= M) {
          ndp[s + (i + 1)] -= M;
        }
      }
    }
    dp = std::move(ndp);
  }
  int ans = (int64_t)dp[sum / 2] * inverse(2, M) % M;
  std::cout << ans << '\n';
  return 0;
}
