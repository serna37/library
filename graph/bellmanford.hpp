template <typename T, typename Graph>
pair<vector<T>, vector<int>> BellmanFord(const Graph &G, int s) {
    int N = G.size(), loop = 0;
    vector<int> route(N, -1);
    vector<T> dis(N, inf<T>);
    dis[s] = 0;
    while (1) {
        ++loop;
        bool upd = 0;
        for (int v = 0; v < N; v++) {
            if (dis[v] == inf<T>) continue;
            for (auto [cost, nv] : G[v]) {
                T asis = dis[nv], tobe = dis[v] + cost;
                if (dis[v] == -inf<T>) tobe = -inf<T>;
                tobe = max(tobe, -inf<T>);
                if (asis > tobe) {
                    if (loop >= N) tobe = -inf<T>;
                    dis[nv] = tobe;
                    route[nv] = v;
                    upd = 1;
                }
            }
        }
        if (!upd) break;
    }
    return {dis, route};
}
