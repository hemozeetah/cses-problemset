#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (int &e : a) {
    std::cin >> e;
  }
  int64_t ans = 0;
  std::map<int64_t, int> cnt;
  cnt[0] = 1;
  int64_t sum = 0;
  for (const int &e : a) {
    sum += e;
    ans += cnt[sum - x];
    cnt[sum] += 1;
  }
  std::cout << ans << '\n';
  return 0;
}
