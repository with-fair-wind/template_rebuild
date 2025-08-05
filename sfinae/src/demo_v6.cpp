#define T1
#ifdef T1
// std::enable_if
#if 0
// 如何要求T必须是int类型呢? SFINAE
template <typename T, typename SFINAE = std::enable_if_t<std::is_same_v<T, int>>>
void f(T) {}

int main() {
    f(1);
    // f(1.);
}
#else
template <typename T, std::enable_if_t<std::is_same_v<T, int>, int *> = nullptr>
void f(T) {}
int main() { f(1); }
#endif
#elif defined(T2)
template <typename Ty, std::size_t N>
struct array {
    Ty arr[N];
};

template <class Type, class... Args>
array(Type, Args...) -> array<std::enable_if_t<(std::is_same_v<Type, Args> && ...), Type>, sizeof...(Args) + 1>;

int main() {
    ::array arr{1., 2, 3, 4, 5};
    // ::array arr{1, 2, 3, 4, 5};

    return 0;
}
#elif defined(T3)
// 我要写一个函数模板 add，我要求传入的对象需要支持默认构造、 + 以及它需要有别名 type ，成员 value、f。
template <typename T, typename = std::void_t<decltype(T{} + T{}), typename T::type, decltype(&T::value), decltype(&T::f)> >
auto add(const T &t1, const T &t2) {
    return t1 + t2;
}

struct Test {
    int value;
    int operator+(const Test &t) const { return this->value + t.value; }
    using type = void;
    void f() const {}
};

int main() {
    Test t{1};
    add(t, t);
}
#elif defined(T4)
// 我要写一个函数模板 add，我要求传入的对象需要支持 + 以及它需要有别名 type ，成员 value、f。
// std::declval
template <typename T, typename = std::void_t<decltype(std::declval<T>() + std::declval<T>()), typename T::type, decltype(&T::value), decltype(&T::f)> >
auto add(const T &t1, const T &t2) {
    return t1 + t2;
}

struct Test {
    int value;
    Test(int v) : value(v) {}
    int operator+(const Test &t) const { return this->value + t.value; }
    using type = void;
    void f() const {}
};

int main() {
    Test t{1};
    add(t, t);
}
#endif