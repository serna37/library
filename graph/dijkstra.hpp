#include <bits/stdc++.h>
using namespace std;
lib_others_inf
lib_graph_base
/**
 * ダイクストラ
 * @brief 単一始点
 * @return 最短距離、経路
 */
template <typename T>
pair<vector<T>, vector<int>> Dijkstra(const Graph<T> &G, int s) {
    int N = G.size();
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, s);
    vector<T> dis(N, inf<T>);
    dis[s] = 0;
    vector<int> route(N, -1);
    while (!q.empty()) {
        auto [dv, v] = q.top();
        q.pop();
        if (dv > dis[v]) continue;
        for (auto &&[from, to, cost, id] : G[v]) {
            T c = dv + cost;
            if (dis[to] > c) {
                dis[to] = c;
                q.emplace(dis[to], to);
                route[to] = v;
            }
        }
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
