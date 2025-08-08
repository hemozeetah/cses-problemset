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
  std::vector<int> f(26);
  for (char c : s) {
    f[c - 'A'] += 1;
  }
  int mid_char = -1;
  for (int i = 0; i < 26; i++) {
    if (f[i] & 1) {
      if (mid_char != -1) {
        std::cout << "NO SOLUTION\n";
        return 0;
      }
      mid_char = i;
    }
  }
  for (int i = 0; i < 26; i++) {
    std::cout << std::string(f[i] / 2, char(i + 'A'));
  }
  if (mid_char != -1) {
    std::cout << char(mid_char + 'A');
  }
  for (int i = 25; i >= 0; i--) {
    std::cout << std::string(f[i] / 2, char(i + 'A'));
  }
  std::cout << '\n';
  return 0;
}
