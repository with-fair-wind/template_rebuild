// "重载决议" : 选择最"匹配"最"合适"的函数
template <typename T>
void test(T) {
    std::puts("template");
}

void test(int) { std::puts("int"); }

int main() {
    test(1);    // 优先选择非模板的普通函数
    test(1.2);  // 隐式实例化
    test("1");
    return 0;
}