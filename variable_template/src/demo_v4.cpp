#define T6
#ifdef T1
struct X {
    static int n;  // 声明
};
int X::n = 0;  // 定义

#elif defined(T2)
struct X {
    const static int n = 10;  // 不是定义，还是声明
};
const int X::n;  // 添加类外定义
// 读取编译时常量，不是“ODR”使用

int main() {
    int b = X::n;                     // 是声明，但是可以通过编译，但是下面的就不行了。涉及逆天规则
    std::cout << &X::n << std::endl;  // error 通过添加第67行定义就可以了
    return 0;
}
#elif defined(T3)
struct X {
    static inline int n = 10;  // 添加内联修饰，此时已经是定义，无需类外定义
};

// 读取编译时常量，不是“ODR”使用

int main() {
    int b = X::n;
    std::cout << &X::n << std::endl;
    return 0;
}
#elif defined(T4)
struct X {
    static constexpr int n = 10;  // 已经是定义，无需类外定义
                                  // constexpr在C++17修饰静态数据成员的时候，蕴含了inline
};

// 读取编译时常量，不是“ODR”使用

int main() {
    int b = X::n;
    std::cout << &X::n << std::endl;
    return 0;
}
#elif defined(T5)
struct limits {
    template <typename T>
    static const T min;
};

template <typename T>
const T limits::min{};

int main() {
    int a = limits::min<int>;
    auto p = &limits::min<int>;
    return 0;
}
#elif defined(T6)
struct limits {
    template <typename T>
    inline static const T min{};  // 或者 constexpr static T min{};
                                  //
};

int main() {
    int a = limits::min<int>;
    auto p = &limits::min<int>;
    return 0;
}
#endif