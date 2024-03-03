#include <bits/stdc++.h>
using namespace std;
// TODO 削除予定
/**
 * セグメント木 区間カウント
 * @brief 削除予定
 */
template <typename T> struct SegRCQ {
  private:
    int N;
    vector<unordered_map<int, int>> node;
    void bind(const int &i) {
        for (auto v : node[i << 1 | 0]) node[i][v.first] += v.second;
        for (auto v : node[i << 1 | 1]) node[i][v.first] += v.second;
    }

  public:
    SegRCQ(int n) : N(n), node(n << 1){};
    SegRCQ(const vector<T> &a) : N(a.size()), node(N << 1) {
        for (int i = 0; i < N; i++) node[i + N][a[i]] = 1;
        for (int i = N - 1; i >= 0; i--) bind(i);
    }
    unordered_map<int, int> operator[](int i) {
        return node[i + N];
    }
    void set(int i, T x) {
        node[i += N] = {x, 1};
        while (i >>= 1) bind(i);
    }
    T get(int l, int r, int x) {
        T vl = 0, vr = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (node[l].count(x)) vl += node[l][x];
                l++;
            }
            if (r & 1) {
                --r;
                if (node[r].count(x)) vl += node[r][x];
            }
        }
        return vl + vr;
    }
    T top() {
        return node[1];
    }
};
