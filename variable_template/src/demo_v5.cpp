struct X {
  const static int n = 10;  // 不是定义，还是声明
};
const int X::n;  // 添加类外定义
// 读取编译时常量，不是"ODR"使用

int main() {
  int b = X::n;  // 是声明，但是可以通过编译，但是下面的就不行了。涉及逆天规则
  std::cout << &X::n << std::endl;  // error 通过添加第67行定义就可以了
  return 0;
}