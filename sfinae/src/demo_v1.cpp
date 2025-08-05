// 待决名消除歧义符
/*
在模板（包括别名模版）的声明或定义中，不是当前实例化的成员且取决于某个模板形参的名字不会被认为是类型
除非使用关键词 typename 或它已经被设立为类型名（例如用 typedef 声明或通过用作基类名）
*/
#if 0
template <typename T>
const typename T::type &f(const T &) { return typename T::type{}; }
// 不会被认为是类型

struct X
{
    using type = int;
};

int main()
{
    X x;
    f(x);
    return 0;
}
#else
int p = 1;

template <typename T>
void foo(const std::vector<T> &v) {
    // std::vector<T>::const_iterator 是待决名，
    typename std::vector<T>::const_iterator it = v.begin();

    // 下列内容因为没有 'typename' 而会被解析成
    // 类型待决的成员变量 'const_iterator' 和某变量 'p' 的乘法。
    // 因为在此处有一个可见的全局 'p'，所以此模板定义能编译。
    typename std::vector<T>::const_iterator *p;  // msvc可以通过编译，但是gcc不行(不加typename)

    typedef typename std::vector<T>::const_iterator iter_t;
    iter_t *p2;  // iter_t 是待决名，但已知它是类型名
}

int main() {
    std::vector<int> v;
    foo(v);  // 实例化失败
}
#endif