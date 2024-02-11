template <typename T> struct Mmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
