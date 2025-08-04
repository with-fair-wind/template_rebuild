#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>


using namespace std::string_literals;

template <typename T>
struct X {
  X(const T &, const T &) {}
};

// 自动推导

int main() {
  X x1{1, 2};
  X x2(1, 2);
  auto x3 = new X{1, 3};
  return 0;
}