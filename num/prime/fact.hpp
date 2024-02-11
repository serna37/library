template <typename T> map<T, int> p_fact(T N) {
    map<T, int> P;
    for (T i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            P[i]++;
            N /= i;
        }
    }
    if (N > 1) P[N]++;
    return P;
}
