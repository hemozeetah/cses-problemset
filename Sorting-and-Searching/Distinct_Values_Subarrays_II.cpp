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
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  int64_t ans = 0;
  std::set<int> st;
  std::map<int, int> cnt;
  int l = 0, r = 0;
  while (l < n) {
    while (r < n && (int)st.size() <= k) {
      if (cnt[a[r]]++ == 0) {
        st.insert(a[r]);
      }
      r += 1;
    }
    ans += r - l - 1 + ((int)st.size() <= k);
    if (--cnt[a[l]] == 0) {
      st.erase(st.find(a[l]));
    }
    l += 1;
  }
  std::cout << ans << '\n';
  return 0;
}
