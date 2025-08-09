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
  std::sort(s.begin(), s.end());
  std::vector<std::string> ans;
  do {
    ans.push_back(s);
  } while (std::next_permutation(s.begin(), s.end()));
  std::cout << (int)ans.size() << '\n';
  for (const std::string &t : ans) {
    std::cout << t << '\n';
  }
  return 0;
}
