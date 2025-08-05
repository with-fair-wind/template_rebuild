// C++ 标准不允许对嵌套类模板进行部分特化
template <typename T, std::size_t N>
struct X {
    template <typename T1, typename T2>
    struct Y {
        void f() const {}
    };
};

template <>
template <typename T2>
struct X<int, 1>::Y<int, T2> {
    void f() const { std::puts("f()"); }
};

int main() {
    X<int, 1>::Y<int, void> y;  // GCC无法识别偏特化版本，无法通过编译，除非主模板中有Y类有f成员函数，只能匹配到主模板
    y.f();
    return 0;
}