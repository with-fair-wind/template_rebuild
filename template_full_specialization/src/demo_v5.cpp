template <typename T>
struct A {
    struct B {};
    template <typename U>
    struct C {};
};

template <>
struct A<void> {
    void f();  // 类内声明
    struct B {};
    template <typename U>
    struct C {};
};
// template<> // 加了错误
void A<void>::f() { std::puts("A<void>::f()"); }  // 类外定义

// 特化成员类 A<char> 的情况下 B 类定义
template <>
struct A<char>::B {
    void f();
};
void A<char>::B::f() { std::puts("A<char>::B::f()"); }  // 类外定义

//  特化成员类 A<int> 的情况下 C 类定义
template <>
template <typename U>
struct A<int>::C {
    void f();
};
template <>
template <typename U>
void A<int>::C<U>::f() {
    std::puts("A<char>::C<U>::f()");
}

/* 不能这样特化
template <typename T>
template <>
struct A<T>::C<double>
{
};
*/

// 类里面有成员函数模板，怎么特化
struct X {
    template <typename T>
    void f(T) {
        std::puts("f<T>");
    }

    // template <>
    // void f<int>(int) { std::puts("f<int>"); } // 类内特化 // gcc编译失败? msvc可以通过
};
template <>
void X::f<double>(double) {
    std::puts("f<double>");
}  // 类内特化

// 特化类模板的成员函数模板
template <typename U>
struct X1 {
    template <typename T>
    void f(T) {
        std::puts("f<T>");
    }

    // template <>
    // void f<int>(int) { std::puts("f<int>"); } // 类内特化 // gcc编译失败? msvc可以通过
};
template <>
template <>
void X1<void>::f<double>(double) {
    std::puts("f<double>");
}  // 类内特化

int main() {
    A<void> a;
    a.f();
    A<char>::B b_c;
    b_c.f();
    A<int>::C<void> c_v;
    c_v.f();
    A<int>::C<int> c_i;
    c_i.f();

    X x;
    x.f(1);
    x.f(1.2);
    x.f("kk");

    X1<void> x1;
    x1.f(1);
    x1.f(1.2);

    return 0;
}