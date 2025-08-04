// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename... Args>
void print(const Args &...args) {
  int _[]{(std::cout << args << ' ', 0)...};
  std::cout << sizeof(_) / sizeof(int) << std::endl;
  std::cout << sizeof...(Args) << ' ' << sizeof...(args) << std::endl;
}
// (std::cout << arg0 << ' ', 0), (std::cout << arg1 << ' ', 0), (std::cout <<
// arg2 << ' ', 0) (std::cout << args << ' ', 0) 模式,
// 逗号表达式,返回0用来初始化数组，无用的数组
int main() {
  print("luse", 1, 1.2);
  return 0;
}