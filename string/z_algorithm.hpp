#include <bits/stdc++.h>
using namespace std;
// TODO
/**
 * Z algorithm
 * @brief Z配列を返却
 * @brief 各[i, 末)部分列と本体との、最長共通接頭辞の長さ
 */
template <typename STRING> // string, vector どちらでも
vector<int> zalgorithm(const STRING &s) {
    int n = int(s.size());
    if (n == 0) return {};
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; ++i) {
        int &k = z[i];
        k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) ++k;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}
