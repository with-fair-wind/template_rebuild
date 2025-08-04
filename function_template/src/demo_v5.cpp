// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename T1, typename T2, typename RT>
RT max(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

void test() {
  // max(1, 1.2); // 无法推导RT -> 解决方式见如下T3、T4、T5
}

int main() {
  test();
  return 0;
}