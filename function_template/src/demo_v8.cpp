// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename T1, typename T2,
          typename RT = decltype(true ? T1{} : T2{})>  // 不求值语境
RT max(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

void test() {
  // max("1", "1.2"s);
  // //msvc好像可以编译通过，而gcc编译失败，三目运算符在gcc中，对于const
  // char[2]、std::string,表达式的类型无法推导出合适的公共类型。
  max(1, 1.2);                              // 此时gcc可以通过编译 RT 为
  using type1 = decltype(true ? 1 : 1.2);   // double
  using type2 = decltype(false ? 1 : 1.2);  // double 公共类型
  std::cout << std::is_same_v<type1, type2> << '\n';
}

int main() {
  test();
  return 0;
}