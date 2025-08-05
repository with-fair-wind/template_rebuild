template <typename T1, typename T2 = void>
struct X {
    static void f() { std::puts("主模板"); }
};

template <typename T>
struct X<T, std::void_t<typename T::type, decltype(&T::f)>> {
    using type = typename T::type;
    static void f() { std::puts("偏特化 T::type"); }
};

struct Test {
    using type = int;
};

struct Test2 {
    using type = double;
    void f() {}
};

int main() {
    X<Test>::f();
    X<int>::f();
    X<Test2>::f();
    return 0;
}