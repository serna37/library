#include <bits/stdc++.h>
using namespace std;
/**
 * 桁和
 */
template <typename T> T digitsum(T a, int N = 10) {
    T ans = 0;
    while (a != 0) {
        ans += a % N;
        a /= N;
    }
    return ans;
}
