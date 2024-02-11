template <typename R>
vector<long long> convolution_fft(const vector<R> &a, const vector<R> &b) {
    using C = FFT::C;
    int need = (int)a.size() + (int)b.size() - 1, nbase = 1;
    while ((1 << nbase) < need) ++nbase;
    FFT::ensure_base(nbase);
    int sz = 1 << nbase;
    vector<C> fa(sz);
    for (int i = 0; i < sz; i++) {
        double x = i < (int)a.size() ? a[i] : 0;
        double y = i < (int)b.size() ? b[i] : 0;
        fa[i] = C(x, y);
    }
    FFT::fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
        fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
        fa[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
        C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * FFT::rts[(sz >> 1) + i];
        fa[i] = A0 + A1 * s;
    }
    FFT::fft(fa, sz >> 1);
    vector<long long> ret(need);
    for (int i = 0; i < need; i++) {
        ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
    }
    return ret;
}
