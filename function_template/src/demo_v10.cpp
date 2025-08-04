template <typename... Args, typename RT = std::common_type_t<Args...>>
RT sum(const Args &...args) {
    RT _[]{static_cast<RT>(args)...};
    // return std::accumulate(std::begin(_), std::end(_), 0); //
    // 根据初值类型决定返回值类型,此时返回类型为int,产生了精度损失
    return std::accumulate(std::begin(_), std::end(_), RT{});  // RT需要有默认构造
}

int main() {
    double ret = sum(1, 2, 3, 5.4);
    std::cout << ret << std::endl;
}