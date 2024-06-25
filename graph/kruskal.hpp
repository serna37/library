#include <bits/stdc++.h>
using namespace std;
lib_others_inf
lib_datastruct_union_find
lib_graph_base
/**
 * 最小全域木
 */
template <typename T> struct MinSpanTree {
    T cost;
    vector<Edge<T>> edges;
};
/**
 * クラスカル O(ElogV)
 * @return 最小全域木
 */
template <typename T, typename UF>
MinSpanTree<T> Kruskal(vector<Edge<T>> edges, int v_cnt) {
    sort(edges.begin(), edges.end(),
         [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });
    UF tree(v_cnt);
    T total = T();
    vector<Edge<T>> es;
    for (auto &&e : edges) {
        if (tree.unite(e.from, e.to)) {
            es.emplace_back(e);
            total += e.cost;
        }
    }
    // 全域に達しない場合
    if (tree.size(0) < v_cnt) {
        total = inf<T>;
    }
    return {total, es};
}
