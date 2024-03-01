#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5;
long long fac[MAX], finv[MAX], inv[MAX];
void extEuclidInv() {
    fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
extEuclidInv();
long long nCk(int n, int k) {
    if (n < k or n < 0 or k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
