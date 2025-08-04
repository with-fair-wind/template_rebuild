#define T6
#ifdef T1
template <typename T = int>
void f() {}

void test() {
    f();          // 默认为f<int>
    f<double>();  // 显示指明
}
#elif defined(T2)
template <typename T1, typename T2, typename RT>
RT max(const T1 &a, const T2 &b) {
    return a > b ? a : b;
}

void test() {
    // max(1, 1.2); // 无法推导RT -> 解决方式见如下T3、T4、T5
}
#elif defined(T3)
template <typename T1, typename T2, typename RT = double>
RT max(const T1 &a, const T2 &b) {
    return a > b ? a : b;
}

void test() { max(1, 1.2); }
#elif defined(T4)
template <typename RT, typename T1, typename T2>
RT max(const T1 &a, const T2 &b) {
    return a > b ? a : b;
}

void test() { max<std::string>("1", "1.2"s); }
#elif defined(T5)
template <typename T1, typename T2, typename RT = decltype(true ? T1{} : T2{})>  // 不求值语境
RT max(const T1 &a, const T2 &b) {
    return a > b ? a : b;
}

void test() {
    // max("1", "1.2"s);    //msvc好像可以编译通过，而gcc编译失败，三目运算符在gcc中，对于const char[2]、std::string,表达式的类型无法推导出合适的公共类型。
    max(1, 1.2);                              // 此时gcc可以通过编译 RT 为
    using type1 = decltype(true ? 1 : 1.2);   // double
    using type2 = decltype(false ? 1 : 1.2);  // double 公共类型
    std::cout << std::is_same_v<type1, type2> << '\n';
}
#elif defined(T6)
template <typename T1, typename T2>
auto max(const T1 &a, const T2 &b) -> decltype(true ? a : b)  // 后置返回类型， auto不是推导而是后置
// 与上一种语法的区别在于，返回类型可能存在不一样
{
    return a > b ? a : b;
}

void test() {
    max("1", "1.2"s);
    max(1, 1.2);
}
#elif defined(T7)
// C++14 引入了返回类型推导
auto max(const auto &a, const auto &b)  // auto 默认没有CV和引用
{
    return a > b ? a : b;
}

decltype(auto) max_(const auto &a, const auto &b)  // 返回引用类型
{
    return a > b ? a : b;
}

void test() {
    max("1", "1.2"s);
    max(1, 1.2);
    max_("1", "1.2"s);
    max_(1, 1.2);
}
#endif

int main() {
    test();
    return 0;
}