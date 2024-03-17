#include <bits/stdc++.h>
using namespace std;
/**
 * 連結成分分解 グリッド
 * @return 連結な頂点群の集合
 */
template <typename Graph>
vector<vector<pair<int, int>>> connected_components_grid(const Graph &G, int H,
                                                         int W) {
    vector<vector<pair<int, int>>> components;
    vector<pair<int, int>> com;
    vector<vector<bool>> seen(H, vector<bool>(W, false));
    auto dfs = [&](auto &f, int y, int x) -> void {
        seen[y][x] = true;
        com.push_back({y, x});
        for (int i = 0; i < (int)dy.size(); ++i) {
            int Y = y + dy[i], X = x + dx[i];
            if (Y < 0 or X < 0 or H <= Y or W <= X) continue;
            if (seen[Y][X]) continue;
            if (G[Y][X] == 0) continue; // 進めるなら
            f(f, Y, X);
        }
    };
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (seen[i][j]) continue;
            if (G[i][j] == 0) continue; // 進めるなら
            com.clear();
            dfs(dfs, i, j);
            components.push_back(com);
        }
    }
    return components;
}
