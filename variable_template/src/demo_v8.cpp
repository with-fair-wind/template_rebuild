struct limits {
  template <typename T>
  static const T min;
};

template <typename T>
const T limits::min{};

int main() {
  int a = limits::min<int>;
  auto p = &limits::min<int>;
  return 0;
}