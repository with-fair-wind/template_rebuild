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
void f(T &&t) {}

template <class Ty>
constexpr Ty &&forward(Ty &Arg) noexcept {
  return static_cast<Ty &&>(Arg);
}

int main() {
  int a = 10;
  f(a);               // f<int &> 参数类型为int &
  f(10);              // f<int &&>
  ::forward<int>(a);  // 无引用折叠，Ty是int
  ::forward<int &>(a);
  ::forward<int &&>(a);
}