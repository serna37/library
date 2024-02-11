template <typename T> struct Mmul {
    using value_type = T;
    static constexpr T e = 1;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x * y;
    }
};
