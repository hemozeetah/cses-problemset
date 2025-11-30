#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

template <typename T>
struct fenwick {
  int n;
  std::vector<T> f;

  fenwick(int n_) : n(n_) {
    f.resize(n);
  }

  void update(int i, T v) {
    while (i < n) {
      f[i] += v;
      i = i | (i + 1);
    }
  }

  T query(int i) const {
    T v{};
    while (i >= 0) {
      v += f[i];
      i = (i & (i + 1)) - 1;
    }
    return v;
  }
};

const int M = 1e9 + 7;

struct info {
  int val;

  info(int val_ = 0) : val(val_) {}

  info &operator+=(const info &rhs) & {
    val += rhs.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  info operator+(const info &rhs) {
    info res = *this;
    return res += rhs;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  auto v = x;
  std::sort(v.begin(), v.end());
  int size = std::unique(v.begin(), v.end()) - v.begin();
  v.resize(size);
  for (int i = 0; i < n; i++) {
    x[i] = std::lower_bound(v.begin(), v.end(), x[i]) - v.begin();
  }
  fenwick<info> dp(size);
  for (int i = 0; i < n; i++) {
    info ways = dp.query(x[i] - 1);
    dp.update(x[i], ways + 1);
  }
  int ans = dp.query(size - 1).val;
  std::cout << ans << '\n';
  return 0;
}
