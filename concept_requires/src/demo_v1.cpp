#define T2
#ifdef T1
// 我需要写一个函数模板 add，想要要求传入的对象必须是支持 operator+ 的，应该怎么写？
template <typename T>
concept Add = requires(T a) { a + a; };  //// "需要表达式 a+a 是可以通过编译的有效表达式"

template <Add T>
auto add(const T &t1, const T &t2) {
    return t1 + t2;
}

int main() {
    struct X {};
    // add(X{}, X{});
    add(1, 2);
    constexpr bool v = Add<int>;
    //> 每个概念都是一个**谓词**，它在**编译时求值**，并在将之用作约束时成为模板接口的一部分。
    std::cout << std::boolalpha << v << std::endl;
    std::cout << std::boolalpha << Add<int> << std::endl;
}
#elif defined(T2)
#if 0
decltype(auto) max(const std::integral auto &a, const std::integral auto &b) { return a > b ? a : b; }
#else
// 定义概念（concept） 时声明的约束表达式，只需要是编译期可得到 bool 类型的表达式即可。
template <typename T>
concept Int = std::is_same_v<T, int>;

decltype(auto) max(const Int auto &a, const Int auto &b) { return a > b ? a : b; }
#endif
int main() {
    ::max(1, 2);
    // ::max('1', '2');
    // ::max(1., 2);
    Int auto a = 1;
}
#endif