template <typename... Args>
void print(const Args &...args) {
    int _[]{(std::cout << args << ' ', 0)...};
    std::cout << sizeof(_) / sizeof(int) << std::endl;
    std::cout << sizeof...(Args) << ' ' << sizeof...(args) << std::endl;
}
// (std::cout << arg0 << ' ', 0), (std::cout << arg1 << ' ', 0), (std::cout <<
// arg2 << ' ', 0) (std::cout << args << ' ', 0) 模式,
// 逗号表达式,返回0用来初始化数组，无用的数组
int main() {
    print("luse", 1, 1.2);
    return 0;
}