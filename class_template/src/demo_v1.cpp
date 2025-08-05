#define T4
#ifdef T1
template <typename T = int, std::size_t N = 10>
struct X {};

int main() {
    X<int> x;
    return 0;
}
#elif defined(T2)
template <typename T>
struct X {
    T t;
};

int main() {
    X x{1};  // C++17 CTAD
    return 0;
}
#elif defined(T3)
template <typename T>
struct X {
    X(const T &, const T &) {}
};

// 自动推导

int main() {
    X x1{1, 2};
    X x2(1, 2);
    auto x3 = new X{1, 3};
    return 0;
}
#elif defined(T4)
template <typename Ty, std::size_t N>
struct array {
    Ty arr[N];
};

// 自定义推导指引
template <typename T, typename... Args>
array(T t, Args...) -> array<T, sizeof...(Args) + 1>;

int main() {
    [[maybe_unused]] std::array arr{1, 2};
    [[maybe_unused]] ::array arr2{1, 2};
    return 0;
}
#elif defined(T5)
// 让一个类模板，如果推导为int，就让它实际成为size_t
template <typename T>
struct Test {
    Test(T v) : t{v} {}

   private:
    T t;
};

Test(int) -> Test<std::size_t>;
template <typename T>
Test(T *) -> Test<T[]>;
// 模板名称(实际被推导类型a)->模板名称<想要让类型a被推导为的类型>

int main() {
    Test t1{1};
    char *p = nullptr;
    Test t2(p);  // t 是 Test<char[]>
    return 0;
}
#endif