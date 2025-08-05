// 折叠表达式
#include <array>        // IWYU pragma: keep
#include <functional>   // IWYU pragma: keep
#include <iostream>     // IWYU pragma: keep
#include <numeric>      // IWYU pragma: keep
#include <string>       // IWYU pragma: keep
#include <tuple>        // IWYU pragma: keep
#include <type_traits>  // IWYU pragma: keep
using namespace std::string_literals;

/*
一元右折叠 `(E 运算符 ...)` 成为 `(E1 运算符 (... 运算符 (EN-1 运算符 EN)))`
一元左折叠 `(... 运算符 E)` 成为 `(((E1 运算符 E2) 运算符 ...) 运算符 EN)`
二元右折叠 `(E 运算符 ... 运算符 I)` 成为 `(E1 运算符 (... 运算符 (EN−1 运算符 (EN 运算符 I)))
二元左折叠 `(I 运算符 ... 运算符 E)` 成为 `((((I 运算符 E1) 运算符 E2) 运算符 ...) 运算符 EN)`
E是使用了形参包的整个表达式
*/