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
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  int64_t ans = 0;
  std::map<int64_t, int> cnt;
  cnt[0] = 1;
  int64_t sum = 0;
  for (const int &e : a) {
    sum += e;
    int r = sum % n;
    if (r < 0) {
      r += n;
    }
    ans += cnt[r];
    cnt[r] += 1;
  }
  std::cout << ans << '\n';
  return 0;
}
