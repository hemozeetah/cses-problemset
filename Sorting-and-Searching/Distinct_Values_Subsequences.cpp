#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int M = 1e9 + 7;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  std::map<int, int> cnt;
  for (const int &e : x) {
    cnt[e] += 1;
  }
  int ans = 1;
  for (const auto &[_, c] : cnt) {
    ans = (long long)ans * (c + 1) % M;
  }
  ans -= 1; // exclude empty subsequence
  if (ans < 0) {
    ans += M;
  }
  std::cout << ans << '\n';
  return 0;
}
