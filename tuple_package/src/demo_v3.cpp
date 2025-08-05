#if 1
// 编译期if
struct Y {
    void f() const { std::puts("f"); }
};

struct X {
    void func() const { std::puts("func"); }
};

template <typename T>
void f(T t) {
    if constexpr (std::is_same_v<T, X>)
        t.func();
    else
        t.f();  // 舍弃语句 但是依然会进行语法检查
}

int main() {
    f(X{});
    f(Y{});
    return 0;
}
#else
template <typename T>
auto f()  // C++14返回类型推导，如果有多个返回语句，必须被推导为相同的类型，但是编译期if可以解决
{
    if constexpr (std::is_same_v<T, int>)
        return 0;
    else
        return 1.0;
}

int main() { f<int>(); }
#endif