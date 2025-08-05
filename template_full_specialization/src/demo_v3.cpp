// 变量模板全特化
#define T2
#ifdef T1
template <typename T>
constexpr const char *s = "??";

template <>
constexpr const char *s<void> = "void";

int main() {
    std::cout << s<void> << std::endl;
    return 0;
}
#elif defined(T2)
template <typename T>
constexpr bool is_void_v = false;

template <>
constexpr bool is_void_v<void> = true;

int main() {
    std::cout << std::boolalpha << ::is_void_v<void> << std::endl;
    std::cout << std::boolalpha << ::is_void_v<int> << std::endl;
    return 0;
}
#endif