template <typename T>
pair<vector<T>, vector<int>> dijkstra(const Graph<T> &G, int s) {
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
        for (auto [from, to, cost, id] : G[v]) {
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
