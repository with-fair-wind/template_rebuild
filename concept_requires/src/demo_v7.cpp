// 复合要求
template <typename T>
concept C = requires(T x) {
    { *x } -> std::convertible_to<typename T::inner>;
    { x + 1 } -> std::same_as<int>;
    { x * 1 } -> std::convertible_to<T>;
    { x.~T() } noexcept;  // 要求x.~T()是不会抛出异常的合法表达式  //析构函数默认是noexcept(比较特殊)
    { x.f() } noexcept;
};
// 表达式{*x}必须合法
// 类型T::inner 必须存在
// 要求{*x}能够隐式转换到 T::inner 类型
// x + 1 必须合法 且必须是int类型 == std::same_as<decltype(x + 1), int>;

struct X {
    void f() noexcept {}
    // ~X() noexcept(false) {}
    int operator*() const { return 0; }
    int operator+(int) const { return 0; }
    X operator*(int) const { return *this; }
    using inner = int;
};

int main() {
    std::cout << std::boolalpha << C<X> << std::endl;
    std::cout << std::boolalpha << std::same_as<int, int> << std::endl;
    std::cout << std::boolalpha << std::same_as<int, void> << std::endl;
}