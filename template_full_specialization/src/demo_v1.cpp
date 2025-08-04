#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <tuple>
#include <type_traits>

// 函数模板全特化
template <typename T1, typename T2>
auto f(const T1 &a, const T2 &b)  // 主函数模板
{
  return a + b;
}

//"定制"需求：传一个double和int类型，则返回相减的结果
template <>
auto f<double, int>(const double &a, const int &b)  // 全特化
{
  return a - b;
}

struct X {
  void f() const {}
};

struct X2 {
  void f2() const {}
};

template <typename T>
void test(const T &t) {
  t.f();
}
template <>
void test<X2>(const X2 &t) {
  t.f2();
}

int main() {
  std::cout << f(2, 1) << std::endl;
  std::cout << f(2., 1) << std::endl;

  X x;
  test(x);
  X x2;
  test(x2);
}