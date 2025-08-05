template <typename T1, typename T2>
const char *s = "?";

template <typename T>
const char *s<int, T> = "T1 == int";

int main() {
    std::cout << s<char, double> << std::endl;
    std::cout << s<int, int *> << std::endl;
    std::cout << s<int, double> << std::endl;
    return 0;
}