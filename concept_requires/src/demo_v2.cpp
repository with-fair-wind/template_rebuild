// requries子句 : requries后面要求是(期待的是)编译期求值,返回bool类型的表达式
template <typename T>
concept add = requires(T a) { a + a; };

template <typename T>
// requires add<T>
// requires std::is_same_v<T, int>
// requires(sizeof(T) >= 4)
    requires requires(T t) { t + t; }
// 第一个requires是requires子句，而第二个requires(T t) { t + t; }是requires表达式，恰恰就是编译期求值
void f(T) {}

int main() {
    f(1);
    // f('a');
}