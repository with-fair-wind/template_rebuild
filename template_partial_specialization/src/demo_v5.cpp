template <class, class>
struct is_same {
    static constexpr bool value = false;
};

template <class Ty>
struct is_same<Ty, Ty> {
    static constexpr bool value = true;
};

#if 0
template <class T1, class T2>
constexpr bool is_same_v = is_same<T1, T2>::value;
#else
template <class T1, class T2>
constexpr bool is_same_v = false;

template <class Ty>
constexpr bool is_same_v<Ty, Ty> = true;
#endif

int main() {
    std::cout << std::boolalpha << ::is_same<int, int>::value << std::endl;
    std::cout << std::boolalpha << ::is_same<int, char>::value << std::endl;
    std::cout << std::boolalpha << ::is_same_v<int, int> << std::endl;
    std::cout << std::boolalpha << ::is_same_v<int, char> << std::endl;
    return 0;
}
