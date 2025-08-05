template <typename T1, typename T2>
struct X {
    void f() const {}
};

template <typename T>
struct X<void, T> {
    void f2() const;
    int a{};
};
template <typename T>
void X<void, T>::f2() const {
    std::puts("f2()");
}

int main() {
    X<void, int> x;
    x.f2();
}