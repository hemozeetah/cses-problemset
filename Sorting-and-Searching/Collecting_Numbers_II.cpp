#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
    e--;
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j) { return x[i] < x[j]; });
  int ans = 1;
  for (int i = 0; i + 1 < n; i++) {
    ans += (ord[i + 1] < ord[i]);
  }
  while (m--) {
    int i, j;
    std::cin >> i >> j;
    i--, j--;
    ans -= (x[i] != 0 && ord[x[i]] < ord[x[i] - 1]);
    ans -= (x[i] != n - 1 && ord[x[i] + 1] < ord[x[i]]);
    ans -= (x[j] != 0 && x[j] - 1 != x[i] && ord[x[j]] < ord[x[j] - 1]);
    ans -= (x[j] != n - 1 && x[j] + 1 != x[i] && ord[x[j] + 1] < ord[x[j]]);
    std::swap(ord[x[i]], ord[x[j]]);
    std::swap(x[i], x[j]);
    ans += (x[i] != 0 && ord[x[i]] < ord[x[i] - 1]);
    ans += (x[i] != n - 1 && ord[x[i] + 1] < ord[x[i]]);
    ans += (x[j] != 0 && x[j] - 1 != x[i] && ord[x[j]] < ord[x[j] - 1]);
    ans += (x[j] != n - 1 && x[j] + 1 != x[i] && ord[x[j] + 1] < ord[x[j]]);
    std::cout << ans << '\n';
  }
  return 0;
}
