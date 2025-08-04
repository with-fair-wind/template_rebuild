// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

// C++14 引入了返回类型推导
auto max(const auto &a, const auto &b)  // auto 默认没有CV和引用
{
  return a > b ? a : b;
}

decltype(auto) max_(const auto &a, const auto &b)  // 返回引用类型
{
  return a > b ? a : b;
}

void test() {
  max("1", "1.2"s);
  max(1, 1.2);
  max_("1", "1.2"s);
  max_(1, 1.2);
}

int main() {
  test();
  return 0;
}