#include <bits/stdc++.h>
using namespace std;
/**
 * 連結成分分解
 * @return 連結な頂点群の集合
 */
template <typename Graph>
vector<vector<int>> connected_components(const Graph &G) {
    vector<vector<int>> components;
    vector<int> com;
    int N = G.size();
    vector<bool> seen(N, false);
    auto dfs = [&](auto &f, int v) -> void {
        seen[v] = true;
        com.push_back(v);
        for (auto [from, to, cost, id] : G[v]) {
            if (seen[to]) continue;
            f(f, to);
        }
    };
    for (int i = 0; i < N; i++) {
        if (seen[i]) continue;
        com.clear();
        dfs(dfs, i);
        components.push_back(com);
    }
    return components;
}
