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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::vector<int> v(a.begin(), a.end());
  std::sort(v.begin(), v.end());
  int len = std::unique(v.begin(), v.end()) - v.begin();
  v.resize(len);
  for (int &x : a) {
    x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
  }
  struct info {
    int val;

    info(int val_ = -1) : val(val_) {}

    info &operator+=(const info &rhs) & {
      val = std::max(val, rhs.val);
      return *this;
    }
  };
  fenwick<info> f(len);
  for (int i = 0; i < n; i++) {
    std::cout << f.query(a[i] - 1).val + 1 << " \n"[i + 1 == n];
    f.update(a[i], i);
  }
  return 0;
}
