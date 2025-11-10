#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int M = 1e9 + 7;

enum OpenState {
  LMR,
  XMX,
  LXR,
  LXX,
  XXR,
  XXX,
};

template <int M>
struct mint {
  int val;

  constexpr mint(int v = 0) : val(v) {}

  constexpr mint &operator+=(const mint &rhs) & {
    val += rhs.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  friend constexpr mint operator+(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    return res += rhs;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  std::vector<int> n(t);
  for (int &x : n) {
    std::cin >> x;
  }
  int mx = *std::max_element(n.begin(), n.end());
  std::vector<std::array<mint<M>, 6>> dp(mx + 1);
  dp[1][XXX] = dp[1][XMX] = 1;
  for (int i = 1; i < mx; i++) {
    const auto &p = dp[i];
    std::array<mint<M>, 6> q;
    q[LMR] = p[LMR] + p[XMX];
    q[XMX] = q[XXX] = std::accumulate(p.begin(), p.end(), mint<M>{});
    q[LXR] = q[LXX] = q[XXR] = p[LXR] + p[LXX] + p[XXR] + p[XXX];
    dp[i + 1] = q;
  }
  for (int i = 0; i < t; i++) {
    mint<M> ans = std::accumulate(dp[n[i]].begin(), dp[n[i]].end(), mint<M>{});
    std::cout << ans.val << '\n';
  }
  return 0;
}
