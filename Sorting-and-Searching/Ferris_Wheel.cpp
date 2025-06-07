#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  while (l <= r) {
    l += (a[l] + a[r] <= x);
    r--;
  }
  int ans = n - r - 1;
  std::cout << ans << '\n';
  return 0;
}
