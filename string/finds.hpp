#include <bits/stdc++.h>
using namespace std;
/**
 * 文字列に含まれる文字列の位置を全て列挙
 * @brief ナイーブ実装
 */
vector<int> finds(const string &T, const string &S) {
    vector<int> pos;
    auto p = T.find(S);
    while (p != string::npos) {
        pos.emplace_back(p);
        p = T.find(S, p + 1);
    }
    return pos;
}
