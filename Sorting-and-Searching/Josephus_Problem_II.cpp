#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

template <class T>
using indexed_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> c(n);
  std::iota(c.begin(), c.end(), 0);
  indexed_set<int> s(c.begin(), c.end());
  std::vector<int> ans(n);
  int pos = 0;
  for (int i = 0; i < n; i++) {
    pos = (pos + k) % (n - i);
    auto it = s.find_by_order(pos);
    assert(it != s.end());
    ans[i] = *it;
    s.erase(it);
  }
  for (const int &x : ans) {
    std::cout << x + 1 << " \n"[x == ans.back()];
  }
  return 0;
}
