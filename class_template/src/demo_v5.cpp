template <typename... Args>
struct X {
    X(Args... args) : value{args...} {}
    std::tuple<Args...> value;
};

int main() {
    std::tuple<int, double> t{1., 1.2};
    // 使用 [[maybe_unused]] 属性来明确表示有意忽略返回值
    [[maybe_unused]] auto val1 = std::get<0>(t);
    [[maybe_unused]] auto val2 = std::get<int>(t);
    X x{1, "kk", 1.2, 's'};
    std::cout << std::get<1>(x.value) << std::endl;

    return 0;
}