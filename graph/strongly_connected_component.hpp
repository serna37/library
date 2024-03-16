#include <bits/stdc++.h>
using namespace std;
/**
 * 辺
 */
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id){};
};
/**
 * グラフ
 */
template <typename T> struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int N) : G(N){};
    vector<Edge<T>> operator[](T v) const {
        return G[v];
    }
    int size() const {
        return G.size();
    }
    void add(int from, int to, T cost = 1, int id = -1) {
        G[from].push_back({from, to, cost, id});
    }
};
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
/**
 * 強連結成分分解
 * @return 強連結成分なグラフ構造のリスト。成分同士の情報ロストに注意
 */
template <typename T> vector<Graph<T>> sccgraph(const Graph<T> &G) {
    int N = G.size();
    vector<vector<int>> components = scc(G);
    vector<Graph<T>> res;
    for (auto &&comp : components) {
        Graph<T> sub(N);
        for (auto &&v : comp) {
            for (auto &&[from, to, cost, id] : G[v]) {
                sub.add(from, to, cost, id);
            }
        }
        res.push_back(sub);
    }
    return res;
}
