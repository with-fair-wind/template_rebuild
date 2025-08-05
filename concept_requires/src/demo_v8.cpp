template <typename T>
concept C = requires(T a) {
    // requires子句要求编译期产生bool值的表达式
    std::is_same_v<T, size_t>;           // 满足语法即可
    requires std::is_same_v<T, double>;  // 要求T是int
    requires std::same_as<T, double>;    // 要求T是int
    requires requires { a + a; };        // 要求a+a 是合法表达式
    a + a;
    requires sizeof(a) > 4;
};

int main() { std::cout << std::boolalpha << C<double> << std::endl; }