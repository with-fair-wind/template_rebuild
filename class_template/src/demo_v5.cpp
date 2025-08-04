#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>

using namespace std::string_literals;

// 让一个类模板，如果推导为int，就让它实际成为size_t
template <typename T>
struct Test {
  Test(T v) : t{v} {}

 private:
  T t;
};

Test(int) -> Test<std::size_t>;
template <typename T>
Test(T *) -> Test<T[]>;
// 模板名称(实际被推导类型a)->模板名称<想要让类型a被推导为的类型>

int main() {
  Test t1{1};
  char *p = nullptr;
  Test t2(p);  // t2 是 Test<char[]>
  return 0;
}