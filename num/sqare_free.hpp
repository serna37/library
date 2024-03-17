#include <bits/stdc++.h>
using namespace std;
/**
 * 平方因子除去
 * @return idx: 自然数, val: 平方因子を除いたもの
 */
vector<int> sqarefree(int mx = 2e5) {
    vector<int> S(mx + 1);
    for (int i = 1; i <= mx; ++i) S[i] = i;
    for (int i = 2; i * i <= mx; ++i) {            // 全平方数
        for (int j = i * i; j <= mx; j += i * i) { // の倍数で割りきる
            while (S[j] % (i * i) == 0) S[j] /= i * i;
        }
    }
    return S;
}
