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
  long long ans = 0;
  int acc_mx = -1;
  for (const int &x : a) {
    acc_mx = std::max(acc_mx, x);
    ans += acc_mx - x;
  }
  std::cout << ans << '\n';
  return 0;
}
