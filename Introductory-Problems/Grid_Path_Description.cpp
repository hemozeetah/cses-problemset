#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

const int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dy[] = {-1, 1, 0, 1, -1, 1, -1, 1};

const int N = 7;
bool visited[N][N];

inline bool isEmpty(int i, int j) {
  return 0 <= std::min(i, j) && std::max(i, j) < N && !visited[i][j];
}

std::string description;

int solve(int i, int j, int step) {
  if (i == N - 1 && j == 0) {
    return (step == N * N - 1);
  }
  if (isEmpty(i - 1, j) == isEmpty(i + 1, j) && isEmpty(i, j - 1) == isEmpty(i, j + 1)) {
    return 0;
  }
  if (!isEmpty(i - 1, j - 1) && isEmpty(i - 1, j) && isEmpty(i, j - 1)) {
    return 0;
  }
  if (!isEmpty(i - 1, j + 1) && isEmpty(i - 1, j) && isEmpty(i, j + 1)) {
    return 0;
  }
  if (!isEmpty(i + 1, j - 1) && isEmpty(i + 1, j) && isEmpty(i, j - 1)) {
    return 0;
  }
  if (!isEmpty(i + 1, j + 1) && isEmpty(i + 1, j) && isEmpty(i, j + 1)) {
    return 0;
  }
  visited[i][j] = true;
  int ways = 0;
  if ((description[step] == '?' || description[step] == 'L') && isEmpty(i, j - 1)) {
    ways += solve(i, j - 1, step + 1);
  }
  if ((description[step] == '?' || description[step] == 'R') && isEmpty(i, j + 1)) {
    ways += solve(i, j + 1, step + 1);
  }
  if ((description[step] == '?' || description[step] == 'U') && isEmpty(i - 1, j)) {
    ways += solve(i - 1, j, step + 1);
  }
  if ((description[step] == '?' || description[step] == 'D') && isEmpty(i + 1, j)) {
    ways += solve(i + 1, j, step + 1);
  }
  visited[i][j] = false;
  return ways;
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> description;
  int answer = solve(0, 0, 0);
  std::cout << answer << '\n';
  return 0;
}
