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
  int n = (int)s.size();
  std::vector<int> f(26);
  for (const char &c : s) {
    f[c - 'A'] += 1;
  }
  bool ok = true;
  for (int i = 0; i < 26; i++) {
    ok &= (f[i] <= (n + 1) / 2);
  }
  if (!ok) {
    std::cout << -1 << '\n';
    return 0;
  }
  std::string ans;
  while ((int)ans.size() != n) {
    for (int i = 0; i < 26; i++) {
      if (f[i] != 0 && (ans.empty() || ans.back() != 'A' + i)) {
        f[i] -= 1;
        ans += 'A' + i;
        int rem = n - (int)ans.size();
        bool ok = true;
        for (int j = 0; j < 26; j++) {
          ok &= f[j] <= (rem + (j != i)) / 2;
        }
        if (ok) {
          break;
        }
        f[i] += 1;
        ans.pop_back();
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}
