// requires表达式 :  产生描述约束的 bool 类型的纯右值表达式。
// 注意，requires 表达式 和 requires 子句，没关系。
// requires { 要求序列 }
// requires(形参列表 (可选)) {要求序列}

// requires表达式里面写的东西，满足语法，能通过编译，就是true否则为false
template <typename T>
void f(T) {
    constexpr bool v1 = requires { T::type; };           // 只要T::type是合法表达式，则返回true，否则为false
    constexpr bool v2 = requires { typename T::type; };  // 只要T::type是合法表达式，则返回true，否则为false
    std::cout << std::boolalpha << "v1: " << v1 << ", v2: " << v2 << std::endl;
}

struct X {
    using type = int;
};

struct Y {
    static constexpr int type = 0;
};

int main() {
    f(1);
    f(X{});
    f(Y{});
    return 0;
}