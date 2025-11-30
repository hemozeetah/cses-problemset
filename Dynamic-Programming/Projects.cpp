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

struct info {
  int64_t val;

  info(int64_t val_ = 0) : val(val_) {}

  info &operator+=(const info &rhs) & {
    val = std::max(val, rhs.val);
    return *this;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i] >> p[i];
  }
  std::vector<int> v;
  v.insert(v.end(), a.begin(), a.end());
  v.insert(v.end(), b.begin(), b.end());
  std::sort(v.begin(), v.end());
  int size = std::unique(v.begin(), v.end()) - v.begin();
  v.resize(size);
  for (int i = 0; i < n; i++) {
    a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    b[i] = std::lower_bound(v.begin(), v.end(), b[i]) - v.begin();
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  fenwick<info> dp(size);
  for (const int &i : ord) {
    int64_t mx = dp.query(a[i] - 1).val;
    dp.update(b[i], mx + p[i]);
  }
  int64_t ans = dp.query(size - 1).val;
  std::cout << ans << '\n';
  return 0;
}
