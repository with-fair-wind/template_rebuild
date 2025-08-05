#define T3
#ifdef T1
void g(double) { std::cout << "g(double)\n"; }
void g(int) { std::cout << "g(int)\n"; }

int main() {
    g(1);
    return 0;
}
#elif defined(T2)
void g(double) { std::cout << "g(double)\n"; }

// 非待决名在模板定义点查找并绑定。即使在模板实例化点有更好的匹配，也保持此绑定
template <typename T>
struct S {
    void f() const {
        g(1);  // 非待决名
    }
};
void g(int) { std::cout << "g(int)\n"; }

int main() {
    g(1);
    S<void> s;
    s.f();
    return 0;
}
#elif defined(T3)
void f() { std::puts("全局"); }
template <typename T>
struct X {
    void f() const { std::puts("X"); }
};

// 非待决名：检查该模板的定义时将进行无限定的名字查找
// 待决名：它的查找会推迟到得知它的模板实参之时

template <typename T>
struct Y : X<T> {
    void t1() const {
        this->f();  // X // ！！！无限定名字查找 //this依赖于模板X，this->f() 是一个待决名
    }
    void t2() const {
        f();  // 全局
    }
};

// 是否this访问成员是有区别的

int main() {
    Y<void> y;
    y.t1();
    y.t2();
    return 0;
}
#endif