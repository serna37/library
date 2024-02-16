template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
};
template <typename T> using Graph = vector<vector<Edge<T>>>;
