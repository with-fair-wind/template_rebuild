struct X {
  static constexpr int n =
      10;  // 已经是定义，无需类外定义
           // constexpr在C++17修饰静态数据成员的时候，蕴含了inline
};

// 读取编译时常量，不是"ODR"使用

int main() {
  int b = X::n;
  std::cout << &X::n << std::endl;
  return 0;
}