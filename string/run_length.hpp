#include <bits/stdc++.h>
using namespace std;
/**
 * ランレングス圧縮
 */
template <typename STRING = string, typename CHAR = char>
vector<pair<CHAR, int>> run_length(STRING &S) {
    vector<pair<CHAR, int>> res;
    for (auto &&x : S) {
        if (res.empty() or res.back().first != x) {
            res.emplace_back(x, 0);
        }
        res.back().second++;
    }
    return res;
}
