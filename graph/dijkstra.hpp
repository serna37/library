template <typename T, typename Graph>
pair<vector<T>, vector<int>> dijkstra(const Graph &G, int s) {
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
        for (auto [cost, nv] : G[v]) {
            T c = dv + cost;
            if (dis[nv] > c) {
                dis[nv] = c;
                q.emplace(dis[nv], nv);
                route[nv] = v;
            }
        }
    }
    return {dis, route};
}
