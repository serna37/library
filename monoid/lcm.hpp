#include <bits/stdc++.h>
using namespace std;
/**
 * 最小公倍数モノイド
 */
template <typename T> struct Mlcm {
    using value_type = T;
    static constexpr T e = 1;
    static constexpr T op(const T &x, const T &y) noexcept {
        return lcm(x, y);
    }
};
