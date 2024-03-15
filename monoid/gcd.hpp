#include <bits/stdc++.h>
using namespace std;
/**
 * 最大公約数モノイド
 */
template <typename T> struct Mgcd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return gcd(x, y);
    }
};
