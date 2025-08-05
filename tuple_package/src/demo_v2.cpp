// 使用模板包装C风格API进行调用
// 经典的 void * + 变参模板
// 简单来说，我们需要写一个类包装一个这样的函数 f ，支持任意可调用对象与任意类型和个数的参数，最终都执行函数 f。
void f(unsigned (*start_address)(void *), void *args) {
    start_address(args);
    std::cout << "f\n";
}

struct X {
    template <typename Fn, typename... Args>
    X(Fn &&func, Args &&...args) {
        using Tuple = std::tuple<std::decay_t<Fn>, std::decay_t<Args>...>;
        auto Decay_copied = std::make_unique<Tuple>(std::forward<Fn>(func), std::forward<Args>(args)...);
        auto Invoker_proc = start<Tuple>(std::make_index_sequence<1 + sizeof...(Args)>{});
        f(Invoker_proc, Decay_copied.release());
    }

    template <typename Tuple, std::size_t... Indices>
    static constexpr auto start(std::index_sequence<Indices...>) noexcept {
        return &Invoke<Tuple, Indices...>;  // 返回函数指针
    }

    template <class Tuple, std::size_t... Indices>
    static unsigned int Invoke(void *RawVals) noexcept {
        const std::unique_ptr<Tuple> FnVals(static_cast<Tuple *>(RawVals));
        Tuple &Tup = *FnVals.get();
        std::invoke(std::move(std::get<Indices>(Tup))...);  // 真正的调用
        return 0;
    }
};

#define T3
#ifdef T1
void func(int &a) { std::cout << &a << '\n'; }

int main() {
    int a{};
    std::cout << &a << '\n';
    func(a);
    X{func, std::ref(a)};
}
#elif defined(T2)
void func(int &a) { std::cout << &a << '\n'; }

int main() {
    int a{};
    std::cout << &a << '\n';
    func(a);
    X{func, a};
}
#elif defined(T3)
void func(const int &a) { std::cout << &a << '\n'; }

int main() {
    int a{};
    std::cout << &a << '\n';
    func(a);
    X{func, a};
}
#endif