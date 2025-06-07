#include <iostream>
#include <string>

const std::string reset = "\033[0m";
const std::string gray = "\033[3;2m";

template <typename T>
struct is_pair : std::false_type {};

template <typename T, typename U>
struct is_pair<std::pair<T, U>> : std::true_type {};

template <typename T>
void __print(const T &x) {
  if constexpr (std::is_same_v<T, char>) {
    std::cerr << '\'' << x << '\'';
  } else if constexpr (std::is_convertible_v<T, std::string_view>) {
    std::cerr << '\"' << x << '\"';
  } else if constexpr (std::is_same_v<T, bool>) {
    std::cerr << (x ? "true" : "false");
  } else if constexpr (std::is_arithmetic_v<T>) {
    std::cerr << x;
  } else if constexpr (is_pair<T>::value) {
    std::cerr << '{';
    __print(x.first);
    std::cerr << ", ";
    __print(x.second);
    std::cerr << '}';
  } else {
    bool f = false;
    std::cerr << '{';
    for (const auto &i : x) {
      std::cerr << (f ? ", " : "");
      __print(i);
      f = true;
    }
    std::cerr << '}';
  }
}

inline void _print() {}

template <typename T, typename... V>
void _print(const T &t, const V &...v) {
  __print(t);
  if constexpr (sizeof...(v) > 0) {
    std::cerr << ", ";
    _print(v...);
  }
}

#define dout(x...)                                                             \
  std::cerr << reset << gray << "[" << #x << "] = [";                          \
  _print(x);                                                                   \
  std::cerr << "]\n" << reset
