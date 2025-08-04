template <typename T>
T max(const T &a, const T &b) {
    return a > b ? a : b;
}  // 只是函数模板的形参类型的一部分

int main() {
    max(1, 2);
    max<double>(1, 1.2);
    max(static_cast<double>(1), 1.2);

    // max<std::string>("kk"s, "1"); // ADL 实参依赖查找
    // 实参为std::string对象，而std::stirng定义在std 而在std中存在max函数
    ::max<std::string>("kk"s, "1");
    ::max("kk"s, std::string("1"));
}