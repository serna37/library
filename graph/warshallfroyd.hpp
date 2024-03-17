#include <bits/stdc++.h>
using namespace std;
lib_others_inf
lib_graph_base
/**
 * ワーシャルフロイド
 * @brief 全頂点対
 * @return 最短距離、負サイクル有無
 */
template <typename T>
pair<vector<vector<T>>, bool> WarshallFroyd(const Graph<T> &G) {
    int N = G.size();
    vector<vector<T>> dis(N, vector<T>(N, inf<T>));
    for (int v = 0; v < N; ++v) {
        dis[v][v] = 0;
        for (auto &&[from, to, cost, id] : G[v]) {
            dis[v][to] = min(dis[v][to], cost);
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (dis[i][k] == inf<T>) continue;
            for (int j = 0; j < N; ++j) {
                if (dis[k][j] == inf<T>) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    bool negativeCycle = false;
    for (int i = 0; i < N; ++i) {
        if (dis[i][i] < 0) {
            negativeCycle = true;
            break;
        }
    }
    return {dis, negativeCycle};
}
