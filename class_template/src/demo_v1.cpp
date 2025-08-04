#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>


using namespace std::string_literals;

template <typename T = int, std::size_t N = 10>
struct X {};

int main() {
  X<int> x;
  return 0;
}