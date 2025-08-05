template <typename... Args>
void print(Args &&...args) {
    (std::cout << ... << args) << std::endl;
}
// 二元左折叠
// I : 初值 std::cout
// 运算法 : <<
// E : args

template <int... I>
constexpr int v1 = (I + ... + 10);  // 二元右折叠

template <int... I>
constexpr int v2 = (10 + ... + I);  // 二元左折叠

int main() {
    print("kk", 1, 1.2);
    std::cout << v1<1, 2, 3, 4> << std::endl;
    // (1+(2+(3+(4+10))))
    std::cout << v2<1, 2, 3, 4> << std::endl;
    // ((((10+1)+2)+3)+4)
    return 0;
}