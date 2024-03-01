#include <bits/stdc++.h>
using namespace std;
/**
 * 階乗
 * @brief ナイーブ
 */
template <typename T> T factorial(T N) {
    T ans = 1;
    while (N > 0) ans *= N--;
    return ans;
}
