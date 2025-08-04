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
  T t;
};

int main() {
  X x{1};  // C++17 CTAD
  return 0;
}