#if 1
template <typename... Args>
void print(const Args &...args) {
    ((std::cout << args << ' '), ...);
}
// 一元右折叠
// E:(std::cout << args << ' ')
// 运算符:,
// 最外层括号是折叠表达式语法的一部分

void print(const char (&args0)[5], const int &args1, const double &args2) { (std::cout << args0 << ' '), ((std::cout << args1 << ' '), (std::cout << args2 << ' ')); }
#else
template <typename... Args>
void print(const Args &...args) {
    (..., (std::cout << args << ' '));
}
// 一元左折叠

void print(const char (&args0)[5], const int &args1, const double &args2) { ((std::cout << args0 << ' '), (std::cout << args1 << ' ')), (std::cout << args2 << ' '); }
#endif

int main() {
    print("kk", 1, 1.2);
    return 0;
}