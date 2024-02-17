template <typename T> vector<vector<T>> WarshallFroyd(const Graph<T> &G) {
    int N = G.size();
    vector<vector<T>> dis(N, vector<T>(N, inf<T>));
    for (int v = 0; v < N; v++) {
        dis[v][v] = 0;
        for (auto [from, to, cost, id] : G[v]) {
            dis[v][to] = min(dis[v][to], cost);
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dis[i][k] == inf<T>) continue;
            for (int j = 0; j < N; j++) {
                if (dis[k][j] == inf<T>) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    return dis;
}
