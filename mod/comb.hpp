#include <bits/stdc++.h>
using namespace std;
/**
 * modコンビネーション
 */
long long mod_combination(int n, int k) {
    return modfact(n) * modinv(modfact(k)) % MOD * modinv(modfact(n - k)) % MOD;
}
