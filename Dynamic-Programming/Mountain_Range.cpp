#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

template <typename T>
struct segtree {
  int n;
  std::vector<T> t;

  segtree(int n_) : n(n_) {
    t.resize(n << 1);
  }

  segtree(const std::vector<T> &a) {
    n = (int)a.size();
    t.resize(n << 1);
    for (int i = 0; i < n; i++) {
      t[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; i--) {
      pull(i);
    }
  }

  inline void pull(int i) {
    t[i] = t[i << 1] + t[i << 1 | 1];
  }

  void update(int i, T v) {
    i += n;
    t[i] = v;
    while (i != 1) {
      pull(i >>= 1);
    }
  }

  T query(int l, int r) const {
    T vl{}, vr{};
    l += n, r += n;
    while (l <= r) {
      if ((l & 1) == 1) {
        vl = vl + t[l++];
      }
      if ((r & 1) == 0) {
        vr = t[r--] + vr;
      }
      l >>= 1, r >>= 1;
    }
    return vl + vr;
  }
};

struct info {
  int val;

  info(int val_ = 0) : val(val_) {}

  friend info operator+(const info &lhs, const info &rhs) {
    return info(std::max(lhs.val, rhs.val));
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for (int &x : h) {
    std::cin >> x;
  }
  std::vector<int> l(n);
  {
    std::stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && h[i] > h[stk.top()]) {
        stk.pop();
      }
      l[i] = (stk.empty() ? -1 : stk.top());
      stk.push(i);
    }
  }
  std::vector<int> r(n);
  {
    std::stack<int> stk;
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && h[i] > h[stk.top()]) {
        stk.pop();
      }
      r[i] = (stk.empty() ? n : stk.top());
      stk.push(i);
    }
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j) {
    return h[i] < h[j];
  });
  segtree<info> dp(n);
  for (const int &i : ord) {
    int mx = dp.query(l[i] + 1, r[i] - 1).val;
    dp.update(i, mx + 1);
  }
  int ans = dp.query(0, n - 1).val;
  std::cout << ans << '\n';
  return 0;
}
