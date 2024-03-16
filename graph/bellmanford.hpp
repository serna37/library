#include <bits/stdc++.h>
using namespace std;
lib_others_inf
lib_graph_base
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
