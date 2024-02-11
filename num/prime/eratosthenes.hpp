template <typename T> vector<bool> eratosthenes(T N) {
    vector<bool> is_P(N + 1, true);
    is_P[0] = is_P[1] = false;
    for (T i = 2; i * i <= N; i++) {
        if (!is_P[i]) continue;
        for (T j = i * i; j <= N; j += i) is_P[j] = false;
    }
    return is_P;
}
