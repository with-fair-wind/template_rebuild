template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

struct X {};

int main() {
    std::cout << max(1, 2) << std::endl;  // 自动推导 隐式实例化
    // std::cout << max(X{}, X{}) << std::endl; //error 实例化失败
    return 0;
}