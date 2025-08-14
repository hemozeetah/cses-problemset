#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int dr[] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dc[] = {-2, -1, 2, 1, -2, -1, 2, 1};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector d(n, std::vector<int>(n, -1));
  d[0][0] = 0;
  std::queue<std::pair<int, int>> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < 8; k++) {
      int ni = i + dr[k];
      int nj = j + dc[k];
      if (std::min(ni, nj) < 0 || n <= std::max(ni, nj) || d[ni][nj] != -1) {
        continue;
      }
      d[ni][nj] = d[i][j] + 1;
      q.emplace(ni, nj);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << d[i][j] << " \n"[j + 1 == n];
    }
  }
  return 0;
}
