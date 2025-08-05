template <int... I>
constexpr int v_right = (I - ...);  // 一元右折叠

template <int... I>
constexpr int v_left = (... - I);  // 一元左折叠

int main() {
    std::cout << v_right<4, 5, 6> << std::endl;  // (4-(5-6))
    std::cout << v_left<4, 5, 6> << std::endl;   // ((4-5)-6)
    return 0;
    // 右折叠就是"先算"右边，左折叠就是"先算"左边
}