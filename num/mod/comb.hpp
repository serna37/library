#include <bits/stdc++.h>
using namespace std;
lib_num_mod_pow
lib_num_mod_inv
lib_num_mod_factorial
/**
 * modコンビネーション
 */
long long mod_combination(int n, int k) {
    return modfact(n) * modinv(modfact(k)) % MOD * modinv(modfact(n - k)) % MOD;
}
