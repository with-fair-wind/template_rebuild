// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

/*可变参数模板*/
// 形参包 C++14
// 形参包展开
void f(const char *, int, double) { std::puts("value"); }
void f(const char **, int *, double *) { std::puts("&"); }
template <typename... Args>
void sum(Args... args)  //  const char* arg0, int arg1, double arg2
{
  f(args...);   // 相当于 f(arg0, arg1, arg2)
  f(&args...);  // 相当于 f(&arg0, &arg1, &arg2)
}
// Args : 类型形参包, args : 函数形参包
// args : 全部传入的参数 Args : 所有参数的类型

// 模式 ...前面的就是模式

int main() {
  sum("luse", 1, 1.2);
  return 0;
}