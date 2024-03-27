#include <bits/stdc++.h>
using namespace std;
/**
 * グリッドの転置
 */
template <typename T> vector<vector<T>> transpose(const vector<vector<T>> &G) {
    int H = G.size(), W = G[0].size();
    swap(H, W);
    vector<vector<T>> A(H, vector<T>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            A[i][j] = G[j][i];
        }
    }
    return A;
}
