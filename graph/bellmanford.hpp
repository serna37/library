#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1e9;
template <> constexpr long long inf<long long> = 1e18;
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
 * ベルマンフォード
 * @brief 単一始点
 * @return 最短距離、経路
 */
template <typename T>
pair<vector<T>, vector<int>> BellmanFord(const Graph<T> &G, int s) {
    int N = G.size(), loop = 0;
    vector<int> route(N, -1);
    vector<T> dis(N, inf<T>);
    dis[s] = 0;
    while (1) {
        ++loop;
        bool upd = 0;
        for (int v = 0; v < N; v++) {
            if (dis[v] == inf<T>) continue;
            for (auto &&[from, to, cost, id] : G[v]) {
                T asis = dis[to], tobe = dis[v] + cost;
                if (dis[v] == -inf<T>) tobe = -inf<T>;
                tobe = max(tobe, -inf<T>);
                if (asis > tobe) {
                    if (loop >= N) tobe = -inf<T>;
                    dis[to] = tobe;
                    route[to] = v;
                    upd = 1;
                }
            }
        }
        if (!upd) break;
    }
    return {dis, route};
}
/**
 * 経路復元
 */
vector<int> route_restore(const vector<int> &route, int goal) {
    vector<int> pth = {goal};
    while (route[pth.back()] != -1) pth.emplace_back(route[pth.back()]);
    reverse(pth.begin(), pth.end());
    return pth;
}
