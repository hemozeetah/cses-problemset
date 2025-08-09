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
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::vector<std::string> all;
  do {
    std::string t(n, ' ');
    for (int i = 0; i < n; i++) {
      t[i] = s[ord[i]];
    }
    all.push_back(t);
  } while (std::next_permutation(ord.begin(), ord.end()));
  std::sort(all.begin(), all.end());
  all.resize(std::unique(all.begin(), all.end()) - all.begin());
  std::cout << (int)all.size() << '\n';
  for (const std::string &t : all) {
    std::cout << t << '\n';
  }
  return 0;
}
