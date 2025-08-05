#define T2
#ifdef T1
// 代换失败不是错误”(Substitution Failure Is Not An Error)

// 在函数模板的重载决议[1] 中会应用此规则：当模板形参在替换成显式指定的类型或推导出的类型失败时，从重载集中丢弃这个特化，而非导致编译失败。(会去找其他的匹配，但是当其他也没有时，编译还是会报错)

template <typename T, typename T2 = typename T::type>
void f(int) {
    std::puts("int");
}

template <typename T, typename T2 = decltype(T{} + T{})>
void f(double) {
    std::puts("double");
}

struct X {
    using type = int;
};

int main() {
    // T:int int::type ? 不符合基本语法 代换失败 丢弃特化
    f<int>(1);
    // T:X X::type = int
    f<X>(1);
    f<X>(1.2);
}
#elif defined(T2)
// 代换失败(SFINAE 错误) 、硬错误
template <typename T>
struct B {
    using type = typename T::type;
};

template <typename T>
void foo(double) {
    std::puts("SFINAE");
}

#if 0
template <class T,
          class V = typename B<T>::type>  // 硬错误
// 应当关注 B<T> 而非 B<T>::type，因为是直接在实例化模板 B 的时候就失败了，被当成硬错误；如果 B<T> 实例化成功，而没有 ::type，则被当成代换失败（不过这里是不可能）
void foo(int) {
    std::puts("SFINAE T::type B<T>::type");
}

int main() {
    foo<void>(1);

    // foo<C>(1);
    // foo<B<C>>(1);
    // foo<C>(1.);
    // foo<B<C>>(1.);
}
#else
template <class T,
          class U = typename T::type,  // 如果T没有别名type 那么就是SFINAE失败(代换失败)
          class V = typename B<T>::type>
void foo(int) {
    std::puts("SFINAE T::type B<T>::type");
}

int main() {
    struct C {
        using type = int;
    };

    foo<void>(1);
    foo<C>(1);
    foo<B<C> >(1);
    foo<C>(1.);
    foo<B<C> >(1.);
}
#endif
#endif