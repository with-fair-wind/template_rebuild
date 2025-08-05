// 模板模板形参
#define T4
#ifdef T1
template <template <typename T> class Ty>
struct X {
    Ty<int> t;
};

template <typename T>
struct Y {
    void f() { std::puts("y"); }
};

template <typename T>
struct Y2 {
    void f() { std::puts("y2"); }
};

int main() {
    X<Y> x;
    x.t.f();
    X<Y2> x1;
    x1.t.f();
    return 0;
}
#elif defined(T2)
template <typename T>
struct Y {};

template <template <typename T> class = Y, typename = int, std::size_t = 10>
struct X {};

int main() { [[maybe_unused]] X x; }
#elif defined(T3)
template <typename T>
struct Y1 {};

template <template <typename T> class... Ty>
struct X {};

template <typename T>
struct Y2 {};

int main() { [[maybe_unused]] X<Y1, Y2, Y2, Y1> x; }
#elif defined(T4)
template <std::size_t>
struct Y1 {};

template <template <std::size_t> class T>
struct X1 {};

template <typename... Args>
struct Y2 {};

template <typename... Args>
struct Y3 {};

template <template <typename... Args> class... Tys>
struct X2 {};

int main() {
    [[maybe_unused]] X1<Y1> x1;
    [[maybe_unused]] X2<Y2, Y3, Y3, Y2> x2;
    return 0;
}
#endif