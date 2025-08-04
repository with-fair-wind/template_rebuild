struct X {
  static inline int n = 10;  // 添加内联修饰，此时已经是定义，无需类外定义
};

// 读取编译时常量，不是"ODR"使用

int main() {
  int b = X::n;
  std::cout << &X::n << std::endl;
  return 0;
}