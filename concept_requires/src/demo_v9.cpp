template <typename T>
concept have_type = requires { typename T::type; };

template <typename T>
struct X {
    static void f() { std::puts("主模板"); }
};

template <have_type T>
struct X<T> {
    using type = typename T::type;
    static void f() { std::puts("偏特化 T::type"); }
};

struct Test {
    using type = int;
};

struct Test2 {
    // using type = double;
    void f() {}
};

int main() {
    X<Test>::f();
    X<int>::f();
    X<Test2>::f();
    return 0;
}