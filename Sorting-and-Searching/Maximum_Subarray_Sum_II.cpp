#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  std::vector<int64_t> p(n + 1);
  for (int i = 0; i < n; i++) {
    p[i + 1] = p[i] + x[i];
  }
  int64_t ans = INT64_MIN;
  std::multiset<int64_t> ms;
  for (int i = a - 1; i < n; i++) {
    if (i >= b) {
      ms.erase(ms.find(p[i - b]));
    }
    ms.insert(p[i - a + 1]);
    ans = std::max(ans, p[i + 1] - *ms.begin());
  }
  std::cout << ans << '\n';
  return 0;
}
