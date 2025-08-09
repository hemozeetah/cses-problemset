#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int N = 8;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<std::string> g(N);
  for (std::string &s : g) {
    std::cin >> s;
  }
  auto solve = [&](auto &&self, int r, auto &&ca, auto &&d1a, auto &&d2a) -> int {
    if (r == N) {
      return 1;
    }
    int ans = 0;
    for (int c = 0; c < N; c++) {
      if (g[r][c] == '.' && !ca[c] && !d1a[r + c] && !d2a[r - c + N - 1]) {
        ca[c] = d1a[r + c] = d2a[r - c + N - 1] = true;
        ans += self(self, r + 1, ca, d1a, d2a);
        ca[c] = d1a[r + c] = d2a[r - c + N - 1] = false;
      }
    }
    return ans;
  };
  int ans = solve(solve, 0, std::vector<bool>(N), std::vector<bool>(2 * N - 1), std::vector<bool>(2 * N - 1));
  std::cout << ans << '\n';
  return 0;
}
