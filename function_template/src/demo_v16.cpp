// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename... Args, typename RT = std::common_type_t<Args...>>
RT sum(const Args &...args) {
  RT _[]{args...};
  // return std::accumulate(std::begin(_), std::end(_), 0); //
  // 根据初值类型决定返回值类型,此时返回类型为int,产生了精度损失
  return std::accumulate(std::begin(_), std::end(_), RT{});  // RT需要有默认构造
}

int main() {
  double ret = sum(1, 2, 3, 5.4);
  std::cout << ret << std::endl;
}