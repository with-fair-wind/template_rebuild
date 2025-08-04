// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>   // IWYU pragma: keep
#include <iostream>     // IWYU pragma: keep
#include <numeric>      // IWYU pragma: keep
#include <type_traits>  // IWYU pragma: keep
using namespace std::string_literals;