#define T2
#ifdef T1
template <typename T>
concept Integral = std::is_integral_v<T>;

// 合取
template <typename T>
concept SignedIntegral = Integral<T> && std::is_signed_v<T>;

void s_f(const SignedIntegral auto &) {}

int main() {
    s_f(1);
    // s_f(1u);
}
#elif defined(T2)
struct X {
    // static constexpr bool value = true;
    int c{};  // 扩大大小
};

// 要求 T 是大小 sizeof 大于 1 且支持一个函数调用

template <typename T>
constexpr bool get_value() {
    return T::value;
}

template <typename T>
// requires(sizeof(T) > 1 && get_value<T>())
    requires(sizeof(T) > 1 || get_value<T>())
void f(T) {}

int main() {
    X x;
    f(x);
    return 0;
}
#endif