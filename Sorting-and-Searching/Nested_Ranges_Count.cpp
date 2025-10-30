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

  inline T query(int l, int r) const {
    return query(r) - query(l - 1);
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<int> a(l.begin(), l.end());
  a.insert(a.end(), r.begin(), r.end());
  std::sort(a.begin(), a.end());
  int len = std::unique(a.begin(), a.end()) - a.begin();
  a.resize(len);
  for (int i = 0; i < n; i++) {
    l[i] = std::lower_bound(a.begin(), a.end(), l[i]) - a.begin();
    r[i] = std::lower_bound(a.begin(), a.end(), r[i]) - a.begin();
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  { // contains other range
    std::sort(ord.begin(), ord.end(), [&](int i, int j) {
      if (l[i] != l[j]) {
        return l[i] > l[j];
      }
      return r[i] < r[j];
    });
    std::vector<int> ans(n);
    fenwick<int> f(len);
    for (int i : ord) {
      ans[i] = f.query(0, r[i]);
      f.update(r[i], 1);
    }
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << " \n"[i + 1 == n];
    }
  }
  { // contained by other range
    std::sort(ord.begin(), ord.end(), [&](int i, int j) {
      if (l[i] != l[j]) {
        return l[i] < l[j];
      }
      return r[i] > r[j];
    });
    std::vector<int> ans(n);
    fenwick<int> f(len);
    for (int i : ord) {
      ans[i] = f.query(r[i], len - 1);
      f.update(r[i], 1);
    }
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}
