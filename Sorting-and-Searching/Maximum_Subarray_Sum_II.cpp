#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) void(0)
#endif

template <typename T, typename F>
struct monostack {
  F op;
  std::vector<std::pair<T, T>> st;

  monostack(const F &f) : op(f) {}

  inline bool empty() const {
    return st.empty();
  }

  inline size_t size() const {
    return st.size();
  }

  inline void clear() {
    st.clear();
  }

  inline void reserve(int n) {
    st.reserve(n);
  }

  inline void push(T x) {
    if (st.empty()) {
      st.emplace_back(x, x);
    } else {
      st.emplace_back(x, op(st.back().second, x));
    }
  }

  inline void pop() {
    st.pop_back();
  }

  inline std::pair<T, T> top() const {
    return st.back();
  }
};

template <typename T, typename F>
struct monoque {
  F op;
  monostack<T, F> p, s;

  monoque(const F &f) : op(f), p(f), s(f) {}

  inline bool empty() const {
    return p.empty() && s.empty();
  }

  inline void clear() {
    p.clear();
    s.clear();
  }

  inline size_t size() const {
    return p.size() + s.size();
  }

  inline void push(T x) {
    s.push(x);
  }

  inline void pop() {
    if (p.empty()) {
      __prepare_front();
    }
    p.pop();
  }

  inline std::pair<T, T> front() {
    if (p.empty()) {
      __prepare_front();
    }
    if (s.empty()) {
      return p.top();
    }
    return std::pair(p.top().first, op(p.top().second, s.top().second));
  }

  inline void __prepare_front() {
    p.reserve(s.size());
    while (!s.empty()) {
      p.push(s.top().first);
      s.pop();
    }
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
  }
  std::vector<int64_t> p(n + 1);
  for (int i = 0; i < n; i++) {
    p[i + 1] = p[i] + x[i];
  }
  int64_t ans = INT64_MIN;
  auto op = [](const int64_t &x, const int64_t &y) {
    return std::min(x, y);
  };
  monoque<int64_t, decltype(op)> mq(op);
  for (int i = a - 1; i < n; i++) {
    if (i >= b) {
      mq.pop();
    }
    mq.push(p[i - a + 1]);
    ans = std::max(ans, p[i + 1] - mq.front().second);
  }
  std::cout << ans << '\n';
  return 0;
}
