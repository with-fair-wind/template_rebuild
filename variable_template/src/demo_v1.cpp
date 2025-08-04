template <typename T>
constexpr T v{};

int main() {
    v<int>;  // 相当于 constexpr int v{} const
    std::cout << std::is_same_v<decltype(v<int>), const int> << std::endl;
    v<double>;  // 两个全局对象，地址不同
    std::cout << &v<double> << std::endl;
    std::cout << &v<int> << std::endl;
}