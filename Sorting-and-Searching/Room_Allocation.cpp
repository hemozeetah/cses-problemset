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
  std::sort(ord.begin(), ord.end(), [&](int i, int j) {
    return l[i] < l[j];
  });
  int len = 0;
  std::set<int> rooms;
  std::set<std::pair<int, int>> departures;
  std::vector<int> ans(n);
  int i = 0;
  while (i < n) {
    while (!departures.empty() && l[ord[i]] > departures.begin()->first) {
      rooms.insert(ans[ord[departures.begin()->second]]);
      departures.erase(departures.begin());
    }
    if (rooms.empty()) {
      len += 1;
      rooms.insert(len);
    }
    ans[ord[i]] = *rooms.begin();
    rooms.erase(rooms.begin());
    departures.emplace(r[ord[i]], i);
    i += 1;
  }
  std::cout << *std::max_element(ans.begin(), ans.end()) << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i + 1 == n];
  }
  return 0;
}
