#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](const int &i, const int &j) {
    return r[i] < r[j];
  });
  std::multiset<int> last_watch;
  for (int i = 0; i < k; i++) {
    last_watch.insert(0);
  }
  int ans = 0;
  for (const int &i : ord) {
    auto it = last_watch.upper_bound(l[i]);
    if (it == last_watch.begin()) {
      continue;
    }
    last_watch.erase(std::prev(it));
    last_watch.insert(r[i]);
    ans += 1;
  }
  std::cout << ans << '\n';
  return 0;
}
