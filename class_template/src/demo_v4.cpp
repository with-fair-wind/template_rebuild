#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>


using namespace std::string_literals;

template <typename Ty, std::size_t N>
struct array {
  Ty arr[N];
};

// 自定义推导指引
template <typename T, typename... Args>
array(T t, Args...) -> array<T, sizeof...(Args) + 1>;

int main() {
  std::array arr{1, 2};
  ::array arr2{1, 2};
  return 0;
}