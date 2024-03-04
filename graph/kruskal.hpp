#include <bits/stdc++.h>
using namespace std;
/**
 * 最小全域木
 */
template <typename T> struct MinSpanTree {
    T cost;
    vector<Edge<T>> edges;
};
/**
 * クラスカル
 * @return 最小全域木
 */
template <typename T> MinSpanTree<T> Kruskal(vector<Edge<T>> edges, int v_cnt) {
    sort(edges.begin(), edges.end(),
         [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });
    UnionFind tree(v_cnt);
    T total = T();
    vector<Edge<T>> es;
    for (auto &&e : edges) {
        if (tree.unite(e.from, e.to)) {
            es.emplace_back(e);
            total += e.cost;
        }
    }
    return {total, es};
}
