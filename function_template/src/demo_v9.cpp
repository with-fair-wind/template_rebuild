template <typename... Args>
void print(const Args &...args) {
    int _[]{(std::cout << args << ' ', 0)...};
}

template <typename T, std::size_t N, typename... Args>
void f(const T (&array)[N], Args... index) {
    print(array[index]...);
    // print(array[index0], array[index1], array[index2]);
}

// const T (&array)[N]是一个数组引用 int 10 const int(&array)[10]
// 内建的数字，它的size是它的类型的一部分, int[1]和int[2]不是一个类型
// N理所应当可以被推导
int main() {
    int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    f(array, 1, 3, 5);
}