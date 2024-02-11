template <typename T> bool is_p(T num) {
    if (num == 2) return true;
    if (num < 2 || num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (T i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
