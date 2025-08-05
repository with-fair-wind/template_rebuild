template <std::size_t... I>
void f(std::index_sequence<I...>) {
    int _[]{(std::cout << I << ' ', 0)...};
}

template <typename... Args>
void print(const std::tuple<Args...> &tuple) {
    [&]<std::size_t... I>(std::index_sequence<I...>) { ((std::cout << std::get<I>(tuple) << ' '), ...); }(std::make_index_sequence<sizeof...(Args)>());
}

int main() {
    f(std::make_index_sequence<10>());  // 生成了一个序列
    std::tuple<int, double> m_tuple{1, 1.2};
    std::cout << '\n' << std::get<0>(m_tuple) << std::endl;
    print(m_tuple);
}