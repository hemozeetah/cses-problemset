#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> k(n);
  for (int &e : k) {
    std::cin >> e;
  }
  int ans = 0;
  int j = 0;
  std::map<int, int> last_occurrence;
  for (int i = 0; i < n; i++) {
    auto it = last_occurrence.find(k[i]);
    if  (it != last_occurrence.end()) {
      j = std::max(j, it->second + 1);
    }
    ans = std::max(ans, i - j + 1);
    last_occurrence[k[i]] = i;
  }
  std::cout << ans << '\n';
  return 0;
}
