#include <bits/stdc++.h>
using namespace std;
/**
 * トポロジカルソート
 */
template <typename Graph> vector<int> topological_sort(const Graph &G) {
    int N = G.size();
    vector<int> seen(N), sorted;
    auto dfs = [&](auto &f, int v) -> void {
        seen[v] = 1;
        for (auto [from, to, cost, i] : G[v]) {
            if (!seen[to]) f(f, to);
        }
        sorted.push_back(v);
    };
    for (int i = 0; i < N; i++) {
        if (!seen[i]) dfs(dfs, i);
    }
    reverse(sorted.begin(), sorted.end());
    return sorted;
}
