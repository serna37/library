template <typename T> struct MAminadd {
    using M_m = Mmin<T>;
    using M_a = Madd<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        (void)size; // unused
        return m == inf<T> ? m : m + a;
    }
};
