#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    int draws = n - (a + b);
    if (draws < 0 || (n != draws && (n - draws == a || n - draws == b))) {
      std::cout << "NO\n";
      continue;
    }
    std::vector<int> p(n), q(n);
    std::iota(p.begin(), p.end(), 1);
    std::iota(q.begin(), q.end(), 1);
    std::rotate(p.begin(), p.begin() + b, p.end() - draws);
    std::cout << "YES\n";
    for (const int &x : p) {
      std::cout << x << " \n"[x == p.back()];
    }
    for (const int &x : q) {
      std::cout << x << " \n"[x == q.back()];
    }
  }
  return 0;
}
