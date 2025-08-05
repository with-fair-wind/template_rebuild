#define Q3
#ifdef Q1
// 特化必须在导致隐式实例化的首次使用之前，在每个发生这种使用的翻译单元中声明

template <typename T>
void f(const T &) {}

void f2() {
    f(1);  // “使用”了函数模板f隐式实例化了f<int>
}

// 顺序错了，得放到f2前面
template <>
void f<int>(const int &) {}

int main() { return 0; }
#elif defined(Q2)
// 只有声明没有定义的模板特化可以像其它不完整类型一样使用(eg：可以使用到它的指针或引用)
template <typename T>  // 主模板声明
class X;
template <>  // 特化声明
class X<int>;

X<int> *p;
// X<int> x //error
#elif defined(Q3)
/* 函数模板和变量模板的显式特化是否为 inline / constexpr / constinit / consteval
只与显式特化自身有关，主模板的声明是否带有对应说明符对它没有影响。
模板声明中出现的属性在它的显式特化中也没有效果：
*/
template <typename T>
int f(T) {
    return 6;
}

template <>
constexpr int f<int>(int) {
    return 6;
}

template <typename T>
constexpr int g(T) {
    return 6;
}

template <>
int g<int>(int) {
    return 6;
}

int main() {
    constexpr auto n = f<int>(0);
    // constexpr auto n = f<double>(0); // error

    // constexpr auto n2 = g<int>(0); // error
    constexpr auto n2 = g<double>(0);  // error
    return 0;
}
#endif