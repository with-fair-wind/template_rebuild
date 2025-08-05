// 类模板全特化
#define T2
#ifdef T1
template <typename T>
struct is_void {
    static constexpr bool value = false;
};

template <>
struct is_void<void> {
    static constexpr bool value = true;
};

template <typename T>
constexpr bool is_void_v = is_void<T>::value;

int main() {
    std::cout << std::boolalpha << std::is_void<void>::value << std::endl;
    std::cout << std::boolalpha << std::is_void<int>::value << std::endl;
    std::cout << std::boolalpha << ::is_void<void>::value << std::endl;
    std::cout << std::boolalpha << ::is_void<int>::value << std::endl;
    std::cout << std::boolalpha << ::is_void_v<void> << std::endl;
    std::cout << std::boolalpha << ::is_void_v<int> << std::endl;
    return 0;
}
#elif defined(T2)
template <typename T>
struct X {
    void f() const { std::puts("f"); }
};

template <>
struct X<int> {
    int n;
    void f() const { std::puts("X<int>"); }
    void f2() const {}
    static constexpr int n2 = 10;
};

int main() {
    X<void> x;
    x.f();
    // x.f2(); // error
    X<int> x_i;
    x_i.f2();
    x_i.f();
    return 0;
}
#endif