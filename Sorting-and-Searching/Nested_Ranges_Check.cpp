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
  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  { // contains other range
    std::sort(ord.begin(), ord.end(), [&](int i, int j) {
      if (l[i] != l[j]) {
        return l[i] > l[j];
      }
      return r[i] < r[j];
    });
    std::vector<int> ans(n);
    int mn = INT_MAX;
    for (int i : ord) {
      ans[i] = (mn <= r[i]);
      mn = std::min(mn, r[i]);
    }
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << " \n"[i + 1 == n];
    }
  }
  { // contained by other range
    std::sort(ord.begin(), ord.end(), [&](int i, int j) {
      if (l[i] != l[j]) {
        return l[i] < l[j];
      }
      return r[i] > r[j];
    });
    std::vector<int> ans(n);
    int mx = -1;
    for (int i : ord) {
      ans[i] = (mx >= r[i]);
      mx = std::max(mx, r[i]);
    }
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}
