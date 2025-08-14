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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << (i ^ j) << " \n"[j + 1 == n];
    }
  }
  return 0;
}
