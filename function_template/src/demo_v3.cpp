template <typename T>
void f(T &&t) {}

template <class Ty>
constexpr Ty &&forward(Ty &Arg) noexcept {
    return static_cast<Ty &&>(Arg);
}

int main() {
    int a = 10;
    f(a);               // f<int &> 参数类型为int &
    f(10);              // f<int &&>
    ::forward<int>(a);  // 无引用折叠，Ty是int
    ::forward<int &>(a);
    ::forward<int &&>(a);
}