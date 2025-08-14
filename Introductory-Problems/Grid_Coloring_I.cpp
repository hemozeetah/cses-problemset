#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> g(n);
  for (int i = 0; i < n; i++) {
    std::cin >> g[i];
  }
  for (int i = 0; i < n; i++) {
    std::string s(m, ' ');
    for (int j = 0; j < m; j++) {
      s[j] = ((i + j) & 1 ? 'A' + (g[i][j] == 'A') : 'C' + (g[i][j] == 'C'));
    }
    std::cout << s << '\n';
  }
  return 0;
}
