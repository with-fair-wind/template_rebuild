// 成员函数模板
template <typename T>
struct Class_template {
    template <typename... Args>
    void f(Args &&...args) {}
};

struct X {
    template <typename... Args>
    void f(Args &&...args) {}
};

int main() {
    Class_template<int> t;
    t.f(1, 2, 3, 1.2);

    X x;
    x.f("1", 1, 2, 1.2);
    return 0;
}