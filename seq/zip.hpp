#include <bits/stdc++.h>
using namespace std;
/**
 * 座標圧縮
 * @return 圧縮後、変換辞書
 */
template <typename T> pair<vector<T>, vector<T>> zip(vector<T> a) {
    vector<T> c = a;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
    return {a, c};
}
