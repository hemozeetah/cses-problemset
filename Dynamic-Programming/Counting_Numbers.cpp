#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

enum NumberState {
  LeadingZeros,
  Tight,
  Less,
};

int64_t solve(int64_t x) {
  if (x < 0) {
    return 0;
  }
  std::string s = std::to_string(x);
  std::vector dp(10, std::vector<int64_t>(3));
  dp[0][LeadingZeros] = 1;
  for (int i = 0; i < (int)s.size(); i++) {
    std::vector ndp(10, std::vector<int64_t>(3));
    for (int pd = 0; pd < 10; pd++) { // prev digit
      for (int d = 0; d < 10; d++) { // digit
        if (pd == 0) {
          if (d == 0) {
            ndp[0][LeadingZeros] = dp[0][LeadingZeros];
          } else if (i != 0 || d <= s[0] - '0') {
            ndp[d][i != 0 || d < s[0] - '0' ? Less : Tight] += dp[0][LeadingZeros];
          }
        }
        if (pd == d) {
          continue;
        }
        if (d <= s[i] - '0') {
          ndp[d][d < s[i] - '0' ? Less : Tight] += dp[pd][Tight];
        }
        ndp[d][Less] += dp[pd][Less];
      }
    }
    dp = std::move(ndp);
  }
  int64_t ans = 0;
  for (int d = 0; d < 10; d++) {
    for (int j = 0; j < 3; j++) {
      ans += dp[d][j];
    }
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int64_t l, r;
  std::cin >> l >> r;
  std::cout << solve(r) - solve(l - 1) << '\n';
  return 0;
}
