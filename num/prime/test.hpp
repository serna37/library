template <typename T> bool is_p(T N) {
    if (N == 2) return true;
    if (N == 1 or N % 2 == 0) return false;
    for (T i = 3; i * i <= N; i += 2) {
        if (N % i == 0) return false;
    }
    return true;
}
