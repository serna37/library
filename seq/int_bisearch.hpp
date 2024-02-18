template <typename T, typename F> T int_bisearch(T ok, T ng, const F &test) {
    while (abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        (test(mid) ? ok : ng) = mid;
    }
    return ok;
}
