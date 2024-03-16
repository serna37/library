#include <bits/stdc++.h>
using namespace std;
// TODO
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1e9;
template <> constexpr long long inf<long long> = 1e18;
/**
 * Slope Trick
 */
struct SlopeTrick {
    static constexpr long long LMIN = -inf<long long>;
    static constexpr long long RMAX = inf<long long>;
    priority_queue<long long> que_l;
    priority_queue<long long, vector<long long>, greater<long long>> que_r;

    long long add_l, add_r;
    __int128 min_f; // infty を足し引きしても壊れないように i128 にする

    SlopeTrick() : add_l(0), add_r(0), min_f(0){};
    SlopeTrick(vector<long long> left, vector<long long> right)
        : que_l(left.begin(), left.end()), que_r(right.begin(), right.end()),
          add_l(0), add_r(0), min_f(0) {
    }
    int size() {
        return (long long)que_l.size() + (long long)que_r.size();
    }
    tuple<long long, long long, __int128> get_min() {
        return {top_L(), top_R(), min_f};
    }
    void add_const(long long a) {
        min_f += a;
    }
    // O(|a| log N)
    void add_linear(long long a, long long b) {
        min_f += b;
        for (int i = 0; i < max<int>(a, 0); i++) {
            long long x = pop_L();
            min_f += x;
            push_R(x);
        }
        for (int i = 0; i < max<int>(-a, 0); i++) {
            long long x = pop_R();
            min_f -= x;
            push_L(x);
        }
    }
    // (a-x)+
    void add_a_minus_x(long long a) {
        min_f += max<long long>(0, a - top_R());
        push_R(a), push_L(pop_R());
    }
    // (x-a)+
    void add_x_minus_a(long long a) {
        min_f += max<long long>(0, top_L() - a);
        push_L(a), push_R(pop_L());
    }
    // |x-a|
    void add_abs(long long a) {
        add_a_minus_x(a);
        add_x_minus_a(a);
    }
    // 増加側を消して、減少側のみにする
    void clear_right() {
        que_r =
            priority_queue<long long, vector<long long>, greater<long long>>();
    }
    // 減少側を消して、増加側のみにする
    void clear_left() {
        que_l = priority_queue<long long>();
    }
    void shift(const long long &a) {
        add_l += a, add_r += a;
    }
    // g(x) = min_{x-b <= y <= x-a} f(y)
    void sliding_window_minimum(const long long &a, const long long &b) {
        add_l += a, add_r += b;
    }
    // O(size log(size))
    __int128 eval(long long x) {
        __int128 y = min_f;
        auto que_l_copy = que_l;
        auto que_r_copy = que_r;
        while (!que_l_copy.empty()) {
            y += max<long long>(0, (que_l_copy.top() + add_l) - x);
            que_l_copy.pop();
        }
        while (!que_r_copy.empty()) {
            y += max<long long>(0, x - (que_r_copy.top() + add_r));
            que_r_copy.pop();
        }
        return y;
    }
    void push_R(const long long &x) {
        que_r.emplace(x - add_r);
    }
    void push_L(const long long &x) {
        que_l.emplace(x - add_l);
    }
    long long top_R() {
        if (que_r.empty()) que_r.emplace(RMAX);
        return que_r.top() + add_r;
    }
    long long top_L() {
        if (que_l.empty()) que_l.emplace(LMIN);
        return que_l.top() + add_l;
    }
    long long pop_R() {
        long long res = top_R();
        que_r.pop();
        return res;
    }
    long long pop_L() {
        long long res = top_L();
        que_l.pop();
        return res;
    }
};
