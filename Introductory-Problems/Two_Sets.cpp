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
  long long sum = (long long)n * (n + 1) / 2;
  if (sum & 1) {
    std::cout << "NO\n";
    return 0;
  }
  long long rem = sum / 2;
  std::vector<int> s[2];
  for (int i = n; i >= 1; i--) {
    if (rem >= i) {
      rem -= i;
      s[0].push_back(i);
    } else {
      s[1].push_back(i);
    }
  }
  assert(rem == 0);
  std::cout << "YES\n";
  for (int i = 0; i < 2; i++) {
    assert(std::accumulate(s[i].begin(), s[i].end(), 0LL) == sum / 2);
    std::cout << s[i].size() << '\n';
    for (int x : s[i]) {
      std::cout << x << " \n"[x == s[i].back()];
    }
  }
  return 0;
}
