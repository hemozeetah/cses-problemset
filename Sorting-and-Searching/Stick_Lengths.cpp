#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const long long INF = 1LL << 60;

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
  }
  std::sort(p.begin(), p.end());
  long long sum = std::accumulate(p.begin(), p.end(), 0LL);
  long long ans = INF;
  long long prefix = 0, suffix = sum;
  for (int i = 0; i < n; i++) {
    suffix -= p[i];
    ans = std::min(ans, (long long)p[i] * i - prefix + suffix - (long long)p[i] * (n - i - 1));
    prefix += p[i];
  }
  std::cout << ans << '\n';
  return 0;
}
