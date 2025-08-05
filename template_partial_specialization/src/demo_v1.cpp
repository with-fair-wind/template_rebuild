template <typename T>
const char *s = "?";  // 主模板

template <typename T>
const char *s<T *> = "pointer";  // 偏特化，对指针，这一"类"类型

template <typename T>
const char *s<T[]> = "array";  // 偏特化，但是只是对T[]这一类型，而不是数组类型

int main() {
    std::cout << s<int *> << std::endl;
    std::cout << s<void *> << std::endl;
    std::cout << s<double *> << std::endl;
    std::cout << s<int> << std::endl;
    // int[]和int[1]不是一个类型
    std::cout << s<int[]> << std::endl;
    std::cout << s<double[]> << std::endl;
    std::cout << s<double[1]> << std::endl;
}