// template 消除歧义符
// 与此相似，模板定义中不是当前实例化的成员的待决名同样不被认为是模板名，除非使用消歧义关键词 template，或它已被设立为模板名
template <typename T>
struct S {
    template <typename U>
    void foo() {}
};

template <typename T>
void bar() {
    S<T> s;
    s.template foo<T>();
};

// 关键词 template 只能以这种方式用于运算符 ::（作用域解析）、->（通过指针的成员访问）和 .（成员访问）之后，下列表达式都是合法示例：

// T::template foo<X>();
// s.template foo<X>();
// this->template foo<X>();
// typename T::template iterator<int>::value_type v;

int main() {
    bar<int>();
    return 0;
}