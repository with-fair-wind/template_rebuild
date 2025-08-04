struct limits {
  template <typename T>
  inline static const T min{};  // 或者 constexpr static T min{};
                                //
};

int main() {
  int a = limits::min<int>;
  auto p = &limits::min<int>;
  return 0;
}