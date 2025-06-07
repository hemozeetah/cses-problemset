#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::vector<int> b(m);
  for (int &x : b) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  int ans = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
      ans++;
      i++, j++;
    } else if (b[j] < a[i] - k) {
      j++;
    } else if (a[i] + k < b[j]) {
      i++;
    } else {
      assert(false);
    }
  }
  std::cout << ans << '\n';
  return 0;
}
