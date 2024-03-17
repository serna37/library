#include <bits/stdc++.h>
using namespace std;
/**
 * Dual Segment Tree
 * @brief 区間更新 1点取得
 */
template <typename Monoid> struct DualSegTree {
    using M = Monoid;
    using T = typename M::value_type;

  private:
    int N, log, size;
    vector<T> lazy;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        size = 1 << log;
        lazy.assign(size << 1, M::e);
    }
    void apply_at(int k, T a) {
        lazy[k] = M::op(lazy[k], a);
    }
    void propagate(int k) {
        if (lazy[k] == M::e) return;
        apply_at((k << 1 | 0), lazy[k]);
        apply_at((k << 1 | 1), lazy[k]);
        lazy[k] = M::e;
    }

  public:
    DualSegTree(int n) : N(n) {
        init();
    }
    DualSegTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) lazy[i + size] = a[i];
    }
    T operator[](int p) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        return lazy[p];
    }
    vector<T> getall() {
        for (int i = 1; i < size; ++i) propagate(i);
        return {lazy.begin() + size, lazy.begin() + size + N};
    }
    void set(int p, const T &x) {
        p += size;
        apply_at(p, x);
        lazy[p] = x;
    }
    void apply(int l, int r, const T &a) {
        if (l == r) return;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        while (l < r) {
            if (l & 1) apply_at(l++, a);
            if (r & 1) apply_at(--r, a);
            l >>= 1, r >>= 1;
        }
    }
};
