#include <bits/stdc++.h>
using namespace std;
/**
 * Segment Tree
 * @brief 1点更新 区間取得
 */
template <typename Monoid> struct SegTree {
    using M = Monoid;
    using T = typename M::value_type;

  private:
    int N, log, size;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        size = 1 << log;
        node.assign(size << 1, M::e);
    }
    void update(const int &i) {
        node[i] = M::op(node[i << 1 | 0], node[i << 1 | 1]);
    }

  public:
    SegTree(int n) : N(n) {
        init();
    }
    SegTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) update(i);
    }
    T operator[](int i) {
        return node[i + size];
    }
    vector<T> getall() {
        return {node.begin() + size, node.begin() + size + N};
    }
    void set(int i, const T &x) {
        node[i += size] = x;
        while (i >>= 1) update(i);
    }
    void act(int i, const T &x) {
        i += size;
        node[i] = M::op(node[i], x);
        while (i >>= 1) update(i);
    }
    T prod(int l, int r) {
        T L = M::e, R = M::e;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::op(L, node[l++]);
            if (r & 1) R = M::op(node[--r], R);
        }
        return M::op(L, R);
    }
    T top() {
        return node[1];
    }
    template <typename F> int max_right(const F &test, int L) {
        if (L == N) return N;
        L += size;
        T sm = M::e;
        do {
            while (L % 2 == 0) L >>= 1;
            if (!test(M::op(sm, node[L]))) {
                while (L < size) {
                    L = 2 * L;
                    if (test(M::op(sm, node[L]))) sm = M::op(sm, node[L++]);
                }
                return L - size;
            }
            sm = M::op(sm, node[L++]);
        } while ((L & -L) != L);
        return N;
    }
    template <typename F> int min_left(const F &test, int R) {
        if (R == 0) return 0;
        R += size;
        T sm = M::e;
        do {
            --R;
            while (R > 1 and (R % 2)) R >>= 1;
            if (!test(M::op(node[R], sm))) {
                while (R < size) {
                    R = 2 * R + 1;
                    if (test(M::op(node[R], sm))) sm = M::op(node[R--], sm);
                }
                return R + 1 - size;
            }
            sm = M::op(node[R], sm);
        } while ((R & -R) != R);
        return 0;
    }
};
