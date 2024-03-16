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
        for (auto &&[from, to, cost, id] : G[v]) {
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
/**
 * 連結成分分解
 * @return 連結なグラフ構造のリスト
 */
template <typename T> vector<Graph<T>> ccgraph(const Graph<T> &G) {
    int N = G.size();
    vector<vector<int>> components = connected_components(G);
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
