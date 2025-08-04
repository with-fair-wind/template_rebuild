template <std::size_t N = 66>
void f() {
    std::cout << N << std::endl;
}

int main() {
    f<100>();
    f();
    return 0;
}