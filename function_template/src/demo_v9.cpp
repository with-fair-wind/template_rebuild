// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename T1, typename T2>
auto max(const T1 &a, const T2 &b)
    -> decltype(true ? a : b)  // 后置返回类型， auto不是推导而是后置
// 与上一种语法的区别在于，返回类型可能存在不一样
{
  return a > b ? a : b;
}

void test() {
  max("1", "1.2"s);
  max(1, 1.2);
}

int main() {
  test();
  return 0;
}