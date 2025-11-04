#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  auto count_subarray_divisions = [&](const int64_t &m) -> int {
    int cnt = 1;
    int64_t s = 0;
    for (int i = 0; i < n; i++) {
      if (s + a[i] > m) {
        s = a[i];
        cnt += 1;
      } else {
        s += a[i];
      }
    }
    return cnt;
  };
  int64_t l = *std::max_element(a.begin(), a.end());
  int64_t r = std::accumulate(a.begin(), a.end(), 0LL);
  while (l <= r) {
    int64_t m = (l + r) >> 1;
    if (count_subarray_divisions(m) <= k) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  std::cout << l << '\n';
  return 0;
}
