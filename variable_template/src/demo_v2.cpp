template <std::size_t N = 66>
constexpr std::size_t v = N;

int main() {
    const int b = v<10>;
    std::cout << b << std::endl;
    std::cout << v<10> << std::endl;
    std::cout << v<> << std::endl;
    return 0;
}