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
  int l = 0, r = 0;
  int sum = 0;
  int ans = 0;
  while (l < n) {
    while (r < n && sum < x) {
      sum += a[r];
      r += 1;
    }
    ans += (sum == x);
    sum -= a[l];
    l += 1;
  }
  std::cout << ans << '\n';
  return 0;
}
