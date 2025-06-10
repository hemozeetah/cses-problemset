#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  std::sort(x.begin(), x.end());
  long long ans = 1;
  for (const int &e : x) {
    if (e > ans) {
      break;
    }
    ans += e;
  }
  std::cout << ans << '\n';
  return 0;
}
