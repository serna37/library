#include <bits/stdc++.h>
using namespace std;
/**
 * コンビネーション O(k)
 */
template <typename T> T nCk(int n, int k) {
    if (k < 0 || n < k) return 0;
    k = min(n - k, k);
    T ret = 1;
    for (T i = 1; i <= k; ++i) {
        ret *= n--;
        ret /= i;
    }
    return ret;
}
