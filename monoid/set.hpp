#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1e9;
template <> constexpr long long inf<long long> = 1e18;
/**
 * 代入モノイド
 */
template <typename T> struct Mset {
    using value_type = T;
    static constexpr T e = inf<T>; // 制約外であること
    static constexpr T op(const T &x, const T &y) noexcept {
        return y == e ? x : y;
    }
};
