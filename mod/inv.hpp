#include <bits/stdc++.h>
using namespace std;
/**
 * 逆元
 * @brief Fermatの小定理
 */
long long modinv(long long a) {
    return modpow(a, MOD - 2);
}
