#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int ans = 0, cnt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (i != 0 && s[i] == s[i - 1]) {
      cnt += 1;
    } else {
      cnt = 1;
    }
    ans = std::max(ans, cnt);
  }
  std::cout << ans << '\n';
  return 0;
}
