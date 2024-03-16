#include <bits/stdc++.h>
using namespace std;
lib_graph_base
/**
 * サイクル検出
 * @return サイクルな辺の集合
 */
template <typename T>
vector<Edge<T>> cycle_detect(const Graph<T> &G, bool directed) {
    int sz = G.size();
    vector<bool> seen(sz), finished(sz);
    vector<Edge<T>> history;
    auto dfs = [&](auto &f, int v, const Edge<T> &e) -> int {
        seen[v] = true;
        history.push_back(e);
        for (const auto &ne : G[v]) {
            auto [from, to, id, cost] = ne;
            if (!directed and to == e.from) continue;
            if (finished[to]) continue;
            if (seen[to] and !finished[to]) {
                history.push_back(ne);
                return to;
            }
            int pos = f(f, to, ne);
            if (pos != -1) return pos;
        }
        finished[v] = true;
        history.pop_back();
        return -1;
    };
    auto restruct = [&](int pos) -> vector<Edge<T>> {
        vector<Edge<T>> cycle;
        while (!history.empty()) {
            const Edge<T> &e = history.back();
            cycle.push_back(e);
            history.pop_back();
            if (e.from == pos) break;
        }
        reverse(cycle.begin(), cycle.end());
        return cycle;
    };
    int pos = -1;
    for (int v = 0; v < sz and pos == -1; ++v) {
        if (seen[v]) continue;
        history.clear();
        pos = dfs(dfs, v, Edge<T>({-1, -1, -1, -1}));
        if (pos != -1) return restruct(pos);
    }
    return vector<Edge<T>>();
}
