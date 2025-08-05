template <typename T = int>
struct X {};

// 只允许在函数作用域以及全局作用域中可以省略<>  >=C++17

struct Test {
    X<> x;  // 类中声明不允许省略<>, 即使满足C++17,同理于静态数据成员
    static inline X<> x2;
};

int main() {
    [[maybe_unused]] X x;     // C++17 ok
    [[maybe_unused]] X<> x2;  // C++11 ok
    return 0;
}