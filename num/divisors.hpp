template <typename T> vector<T> divisors(T a) {
    vector<T> ans;
    for (int i = 1; i * i <= a; i++) {
        if (a % i != 0) continue;
        ans.push_back(i);
        if (a / i != i) ans.push_back(a / i);
    }
    return ans;
}
