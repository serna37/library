template <class T> struct StarrySkyTree {
  private:
    int N, log, sz;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        sz = 1 << log;
        node.assign(sz << 1, -inf<T>);
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
        for (int i = 0; i < N; ++i) node[i + sz] = a[i];
        for (int i = sz - 1; i >= 1; --i) node[i] = _star(i);
    }
    T operator[](int i) {
        return sum(i + sz);
    }
    T get(int l, int r) {
        T ans = -inf<T>;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, sum(l++));
            if (r & 1) ans = max(ans, sum(--r));
        }
        return ans;
    }
    T top() {
        return node[1];
    }
    void apply(int l, int r, const T &x) {
        for (int ll = (l += sz), rr = (r += sz); ll < rr; ll >>= 1, rr >>= 1) {
            if (ll & 1) node[ll++] += x;
            if (rr & 1) node[--rr] += x;
        }
        l >>= __builtin_ctz(l);
        r >>= __builtin_ctz(r);
        while (l >>= 1) star(l);
        while (r >>= 1) star(r);
    }
};
