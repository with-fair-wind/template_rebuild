// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename T>
T max(T a, T b) {
  return a > b ? a : b;
}

struct X {};

int main() {
  std::cout << max(1, 2) << std::endl;  // 自动推导 隐式实例化
  // std::cout << max(X{}, X{}) << std::endl; //error 实例化失败
  return 0;
}