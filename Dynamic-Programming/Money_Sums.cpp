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
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  int sum = std::accumulate(x.begin(), x.end(), 0);
  std::vector<bool> dp(sum + 1);
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    std::vector<bool> ndp(sum + 1);
    for (int s = 0; s <= sum; s++) {
      if (dp[s]) {
        ndp[s] = true;
        ndp[s + x[i]] = true;
      }
    }
    dp = std::move(ndp);
  }
  std::vector<int> ans;
  for (int s = 1; s <= sum; s++) {
    if (dp[s]) {
      ans.push_back(s);
    }
  }
  std::cout << ans.size() << '\n';
  for (const int &s : ans) {
    std::cout << s << " \n"[s == ans.back()];
  }
  return 0;
}
