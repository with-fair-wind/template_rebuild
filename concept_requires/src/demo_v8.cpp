template <typename T>
concept C = requires(T a) {
    // ==================== requires表达式中的各种要求 ====================

    // 1. 简单表达式检查：检查语法是否合法，不要求返回特定类型
    std::is_same_v<T, size_t>;  // 检查：T是否与size_t相同
                                // 注意：这里只是检查语法，不要求结果为true

    // 2. requires子句：要求编译期产生bool值且为true
    requires std::is_same_v<T, double>;  // 要求：T必须是double类型
                                         // 如果T不是double，整个concept为false

    // 3. 使用std::same_as concept
    requires std::same_as<T, double>;  // 要求：T必须是double类型
                                       // 等价于上面的写法，但使用C++20 concept

    // 4. 嵌套requires表达式：检查特定操作是否合法
    requires requires { a + a; };  // 要求：a + a 必须是合法表达式
                                   // 外层requires是子句，内层requires是表达式

    // 5. 简单操作检查：检查语法是否合法
    a + a;  // 检查：a + a 是否是合法表达式
            // 不要求返回特定类型，只检查语法

    // 6. 编译期常量表达式检查
    requires sizeof(a) > 4;  // 要求：a的大小必须大于4字节
                             // sizeof(a)是编译期常量，>4是bool表达式
};

// ==================== 详细解释 ====================

/*
requires表达式语法：requires (参数列表) { 要求列表 }

要求列表中可以包含：
1. 简单表达式：检查语法是否合法
2. requires子句：要求编译期bool表达式为true
3. 类型要求：typename T::some_type
4. 复合要求：{ expression } -> type-constraint

关键区别：
- 简单表达式（如 a + a）：只检查语法，不要求结果
- requires子句（如 requires sizeof(a) > 4）：要求bool表达式为true
- 嵌套requires：外层是子句，内层是表达式
*/

// ==================== 测试函数 ====================
void test_concept() {
    std::cout << "=== 测试Concept C ===" << std::endl;

    // 测试double类型
    std::cout << "C<double>: " << std::boolalpha << C<double> << std::endl;

    // 测试int类型
    std::cout << "C<int>: " << std::boolalpha << C<int> << std::endl;

    // 测试size_t类型
    std::cout << "C<size_t>: " << std::boolalpha << C<size_t> << std::endl;

    // 测试char类型（大小小于4字节）
    std::cout << "C<char>: " << std::boolalpha << C<char> << std::endl;
}

// ==================== 等价写法示例 ====================

// 等价于上面的concept C，但更清晰
template <typename T>
concept C_Equivalent = std::same_as<T, double> &&  // T必须是double
                       requires(T a) {
                           a + a;                   // 支持加法
                           requires sizeof(a) > 4;  // 大小大于4字节
                       };

// ==================== 实际应用示例 ====================

// 使用concept C的函数
template <typename T>
    requires C<T>
void process_value(T value) {
    std::cout << "Processing value: " << value << std::endl;
    std::cout << "Size: " << sizeof(value) << " bytes" << std::endl;
    std::cout << "Double value: " << value + value << std::endl;
}

// ==================== requires子句返回false的详细解释 ====================

/*
requires子句返回false的含义：

1. 概念层面：
   - requires子句是约束条件
   - 返回false表示该约束条件不满足
   - 整个concept或模板函数不适用于该类型

2. 编译行为：
   - 不会导致编译错误
   - 只是让concept返回false
   - 模板函数不会被实例化

3. 实际影响：
   - 类型不满足约束条件
   - 模板函数调用失败
   - 编译器会寻找其他重载或报错
*/

// 示例：演示requires子句返回false的情况
template <typename T>
concept SizeCheck = requires(T t) {
    requires sizeof(t) > 8;  // 要求大小大于8字节
};

template <typename T>
concept TypeCheck = requires(T t) {
    requires std::is_integral_v<T>;  // 要求是整数类型
};

// 测试函数
template <typename T>
    requires SizeCheck<T>
void process_large(T value) {
    std::cout << "Processing large value: " << value << std::endl;
}

template <typename T>
    requires TypeCheck<T>
void process_integer(T value) {
    std::cout << "Processing integer: " << value << std::endl;
}

void test_requires_false() {
    std::cout << "\n=== 测试requires子句返回false的情况 ===" << std::endl;

    // 测试SizeCheck concept
    std::cout << "SizeCheck<int>: " << std::boolalpha << SizeCheck<int> << std::endl;                  // false: int大小为4字节
    std::cout << "SizeCheck<double>: " << std::boolalpha << SizeCheck<double> << std::endl;            // false: double大小为8字节
    std::cout << "SizeCheck<long double>: " << std::boolalpha << SizeCheck<long double> << std::endl;  // true: 通常大于8字节

    // 测试TypeCheck concept
    std::cout << "TypeCheck<int>: " << std::boolalpha << TypeCheck<int> << std::endl;        // true: int是整数
    std::cout << "TypeCheck<double>: " << std::boolalpha << TypeCheck<double> << std::endl;  // false: double不是整数
    std::cout << "TypeCheck<char>: " << std::boolalpha << TypeCheck<char> << std::endl;      // true: char是整数

    // 测试函数调用
    // process_large(42);        // 编译错误：int不满足SizeCheck
    // process_integer(3.14);    // 编译错误：double不满足TypeCheck
    process_integer(42);  // 编译成功：int满足TypeCheck
}

// ==================== 复杂约束示例 ====================

template <typename T>
concept ComplexConstraint = requires(T t) {
    // 多个requires子句，全部为true时concept才为true
    requires std::is_arithmetic_v<T>;       // 必须是算术类型
    requires sizeof(T) >= 4;                // 大小至少4字节
    requires requires { t + t; };           // 支持加法
    requires requires { std::cout << t; };  // 支持流输出
};

void test_complex_constraint() {
    std::cout << "\n=== 测试复杂约束 ===" << std::endl;

    std::cout << "ComplexConstraint<int>: " << std::boolalpha << ComplexConstraint<int> << std::endl;                  // true
    std::cout << "ComplexConstraint<double>: " << std::boolalpha << ComplexConstraint<double> << std::endl;            // true
    std::cout << "ComplexConstraint<char>: " << std::boolalpha << ComplexConstraint<char> << std::endl;                // false: 大小小于4字节
    std::cout << "ComplexConstraint<std::string>: " << std::boolalpha << ComplexConstraint<std::string> << std::endl;  // false: 不是算术类型
}

int main() {
    test_concept();
    test_requires_false();
    test_complex_constraint();

    // 测试函数调用
    std::cout << "\n=== 测试函数调用 ===" << std::endl;
    process_value(3.14);  // 应该能编译通过

    return 0;
}