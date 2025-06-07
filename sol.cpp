#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  dout(n);
  dout(a);
  dout(1);
  dout(1LL << 60);
  dout(3.14);
  dout('a');
  dout("testing");
  dout(true);
  dout(std::pair("ok", 12));
  dout(std::vector{1, 2, 3, 2});
  dout(std::set{1, 2, 3, 2});
  dout(std::vector{std::pair(1, "test"), std::pair(3, "test")});
  dout();
  std::cout << "hello cses\n";
  return 0;
}
