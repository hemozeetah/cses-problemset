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
  std::vector<int> a(n), d(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> d[i];
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int64_t cur = 0, ans = 0;
  for (const int &i : ord) {
    cur += a[i];
    ans += d[i] - cur;
  }
  std::cout << ans << '\n';
  return 0;
}
