#include <bits/stdc++.h>
using namespace std;
/**
 * 星空木
 * @brief 区間加算 区間max取得
 * @brief rev = trueで区間minに変更
 */
template <typename T, bool rev = false> struct StarrySkyTree {
  private:
    int N, log, sz, rv;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        sz = 1 << log;
        node.assign(sz << 1, -inf<T>);
        rv = (rev ? -1 : 1);
    }
    T _star(int i) {
        T mx = max(node[i << 1 | 0], node[i << 1 | 1]);
        node[i << 1 | 0] -= mx;
        node[i << 1 | 1] -= mx;
        return mx;
    }
    void star(int i) {
        node[i] += _star(i);
    }
    T sum(int i) {
        T ans = node[i];
        while (i >>= 1) ans += node[i];
        return ans;
    }

  public:
    StarrySkyTree(int n) : N(n) {
        init();
    }
    StarrySkyTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + sz] = a[i] * rv;
        for (int i = sz - 1; i >= 1; --i) node[i] = _star(i);
    }
    T operator[](int i) {
        return sum(i + sz) * rv;
    }
    vector<T> getall() {
        vector<T> res(N);
        for (int i = 0; i < N; i++) res[i] = sum(i + sz) * rv;
        return res;
    }
    void set(int p, const T &x) {
        apply(p, p + 1, x - sum(p + sz) * rv);
    }
    void act(int p, const T &x) {
        apply(p, p + 1, x);
    }
    T get(int l, int r) {
        T ans = -inf<T>;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, sum(l++));
            if (r & 1) ans = max(ans, sum(--r));
        }
        return ans * rv;
    }
    T top() {
        return node[1] * rv;
    }
    void apply(int l, int r, const T &x) {
        T v = x * rv;
        for (int ll = (l += sz), rr = (r += sz); ll < rr; ll >>= 1, rr >>= 1) {
            if (ll & 1) node[ll++] += v;
            if (rr & 1) node[--rr] += v;
        }
        l >>= __builtin_ctz(l);
        r >>= __builtin_ctz(r);
        while (l >>= 1) star(l);
        while (r >>= 1) star(r);
    }
};
