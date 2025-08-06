#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// ==================== requires表达式 (requires expression) ====================
// requires表达式是一种编译期表达式，用于检查类型是否满足特定的语法要求
// 语法：requires (参数列表) { 要求列表 }

// 示例1：检查类型是否支持加法操作
template <typename T>
concept Addable = requires(T a, T b) {
    a + b;  // 要求类型T支持+操作
};

// 示例2：检查类型是否支持多种操作
template <typename T>
concept Container = requires(T t) {
    typename T::value_type;                               // 要求有value_type类型别名
    typename T::iterator;                                 // 要求有iterator类型别名
    { t.begin() } -> std::same_as<typename T::iterator>;  // begin()返回iterator
    { t.end() } -> std::same_as<typename T::iterator>;    // end()返回iterator
    { t.size() } -> std::convertible_to<std::size_t>;     // size()返回可转换为size_t的类型
};

// 示例3：检查类型是否支持特定操作和返回类型
template <typename T>
concept StringLike = requires(T t) {
    { t.c_str() } -> std::convertible_to<const char*>;   // c_str()返回const char*
    { t.length() } -> std::convertible_to<std::size_t>;  // length()返回size_t
};

// ==================== requires子句 (requires clause) ====================
// requires子句用于在模板参数或函数声明中指定约束条件
// 语法：requires 约束表达式

// 示例1：使用concept作为约束
template <typename T>
    requires Addable<T>  // requires子句，使用Addable concept
void add_and_print(T a, T b) {
    std::cout << "Result: " << a + b << std::endl;
}

// 示例2：使用requires表达式作为约束
template <typename T>
    requires requires(T t) { t + t; }  // 第一个requires是子句，第二个是表达式
void add_self(T t) {
    std::cout << "Self add: " << t + t << std::endl;
}

// 示例3：使用逻辑组合
template <typename T>
    requires Addable<T> && std::is_arithmetic_v<T>  // 组合多个约束
void arithmetic_add(T a, T b) {
    std::cout << "Arithmetic add: " << a + b << std::endl;
}

// 示例4：使用Container concept
template <typename T>
    requires Container<T>
void print_container(const T& container) {
    for (const auto& item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// ==================== 等价写法对比 ====================

// 方法1：使用requires子句
template <typename T>
    requires Addable<T>
void method1(T a, T b) {
    std::cout << a + b << std::endl;
}

// 方法2：使用concept作为模板参数约束
template <Addable T>
void method2(T a, T b) {
    std::cout << a + b << std::endl;
}

// 方法3：使用requires表达式直接作为约束
template <typename T>
    requires requires(T a, T b) { a + b; }
void method3(T a, T b) {
    std::cout << a + b << std::endl;
}

// ==================== 复杂示例 ====================

// 检查类型是否支持流输出
template <typename T>
concept Printable = requires(std::ostream& os, T t) {
    { os << t } -> std::convertible_to<std::ostream&>;
};

// 检查类型是否支持比较操作
template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
    { a == b } -> std::convertible_to<bool>;
};

// 组合多个约束的复杂函数
template <typename T>
    requires Addable<T> && Printable<T> && Comparable<T>
void complex_operation(T a, T b) {
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
}

// ==================== 测试函数 ====================
void test_requires() {
    std::cout << "=== 测试requires表达式与requires子句 ===" << std::endl;

    // 测试Addable concept
    add_and_print(5, 3);  // 整数支持加法
    add_self(10);         // 整数支持自加

    // 测试Container concept
    std::vector<int> vec = {1, 2, 3, 4, 5};
    print_container(vec);

    // 测试复杂约束
    complex_operation(10, 20);

    // 测试StringLike concept
    std::string str = "Hello";
    if constexpr (StringLike<std::string>) {
        std::cout << "String length: " << str.length() << std::endl;
        std::cout << "String c_str: " << str.c_str() << std::endl;
    }

    // 测试等价写法
    method1(15, 25);
    method2(35, 45);
    method3(55, 65);
}

int main() {
    test_requires();
    return 0;
}