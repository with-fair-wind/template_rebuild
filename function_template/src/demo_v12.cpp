// 函数模板不是函数，函数模板必须实例化，才会生成实际的函数定义 ->
// 粗略理解，模板只有"用了"它，才会生成实际代码 C++ 模板是"静态" 编译期
// 没有运行时的开销

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>

using namespace std::string_literals;

// "重载决议" : 选择最"匹配"最"合适"的函数
template <typename T>
void test(T) {
  std::puts("template");
}

void test(int) { std::puts("int"); }

int main() {
  test(1);    // 优先选择非模板的普通函数
  test(1.2);  // 隐式实例化
  test("1");
  return 0;
}