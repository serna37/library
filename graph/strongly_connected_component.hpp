#include <bits/stdc++.h>
using namespace std;
/**
 * 強連結成分分解
 * @return sccのid、scc集合
 */
template <typename Graph>
pair<int, vector<int>> strongly_connected_component(const Graph &G) {
    int N = G.size(), C = 0, now = 0;
    vector<int> comp(N), low(N), ord(N, -1), pth;
    auto dfs = [&](auto &f, int v) -> void {
        low[v] = ord[v] = now++;
        pth.emplace_back(v);
        for (auto &&[from, to, cost, id] : G[v]) {
            if (ord[to] == -1) {
                f(f, to);
                low[v] = min(low[v], low[to]);
            } else {
                low[v] = min(low[v], ord[to]);
            }
        }
        if (low[v] == ord[v]) {
            while (1) {
                int u = pth.back();
                pth.pop_back();
                ord[u] = N, comp[u] = C;
                if (u == v) break;
            }
            ++C;
        }
    };
    for (int v = 0; v < N; v++) {
        if (ord[v] == -1) dfs(dfs, v);
    }
    for (int v = 0; v < N; v++) {
        comp[v] = C - 1 - comp[v];
    }
    return {C, comp};
}
/**
 * 強連結成分分解
 * @return scc集合のリスト。トポソ順
 */
template <typename Graph> vector<vector<int>> scc(const Graph &G) {
    auto [cnt, ids] = strongly_connected_component(G);
    vector<int> c(cnt);
    vector<vector<int>> g(cnt);
    for (auto &&v : ids) c[v]++;
    for (int i = 0; i < cnt; i++) g[i].reserve(c[i]);
    for (int i = 0; i < G.size(); i++) g[ids[i]].push_back(i);
    return g;
}
