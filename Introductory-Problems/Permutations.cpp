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
  for (int i = 0; i < n; i += 2) {
    a[(n - 1) / 2 - i / 2] = i;
  }
  for (int i = 1; i < n; i += 2) {
    a[n - (i + 1) / 2] = i;
  }
  for (int i = 0; i + 1 < n; i++) {
    if (std::abs(a[i] - a[i + 1]) == 1) {
      std::cout << "NO SOLUTION\n";
      return 0;
    }
  }
  for (const int &x : a) {
    std::cout << x + 1 << " \n"[x == a.back()];
  }
  return 0;
}
