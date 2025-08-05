// 简单要求
template <typename T>
concept Addable = requires(T a, T b) { a + b; };

template <typename T, class U>
concept Swappable = requires(T &&t, U &&u) {
    swap(std::forward<T>(t), std::forward<U>(u));
    swap(std::forward<U>(u), std::forward<T>(t));
};

template <typename T>
    requires(Addable<T> && Swappable<T, T>)
struct Test {};

namespace loser {
struct X {
    X operator+(const X &) const { return *this; }
};

void swap(const X &, const X &) {}
};  // namespace loser

int main() {
    // 实参依赖查找， X和swap函数在一个命名空间，所以swap可以不加限定
    Test<loser::X> test;
    std::cout << std::boolalpha << Addable<loser::X> << '\n';              // true
    std::cout << std::boolalpha << Swappable<loser::X, loser::X> << '\n';  // true

    return 0;
}