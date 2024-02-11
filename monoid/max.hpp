template <typename T> struct Mmax {
    using value_type = T;
    static constexpr T e = -inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return max(x, y);
    }
};
