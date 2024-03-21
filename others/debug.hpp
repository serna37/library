#include <bits/stdc++.h>
using namespace std;
// ==========================================================================
// ==========================================================================
// --- debug_start
// =====================================
// primitive
// =====================================
void _print(const int &v) {
    cerr << v;
}
void _print(const long long &v) {
    cerr << v;
}
void _print(const double &v) {
    cerr << v;
}
void _print(const string &v) {
    cerr << '"' << v << '"';
}
void _print(const char &v) {
    cerr << "'" << v << "'";
}
void _print_start() {
    cerr << "{";
}
void _print_end() {
    cerr << "}";
}
void _print_p_start() {
    cerr << "(";
}
void _print_p_end() {
    cerr << ")";
}
void _print_sep() {
    cerr << ", ";
}
void _print_LF() {
    cerr << "\n";
}
// =====================================
// pair tuple
// =====================================
template <typename T, typename U> void _print(const pair<T, U> &v) {
    _print_p_start();
    _print(v.first);
    _print_sep();
    _print(v.second);
    _print_p_end();
}
template <typename T, typename U, typename R>
void _print(const tuple<T, U, R> &v) {
    _print_p_start();
    _print(get<0>(v));
    _print_sep();
    _print(get<1>(v));
    _print_sep();
    _print(get<2>(v));
    _print_p_end();
}
template <typename T, typename U, typename R, typename S>
void _print(const tuple<T, U, R, S> &v) {
    _print_p_start();
    _print(get<0>(v));
    _print_sep();
    _print(get<1>(v));
    _print_sep();
    _print(get<2>(v));
    _print_sep();
    _print(get<3>(v));
    _print_p_end();
}
// =====================================
// vector vector2 set multiset map
// =====================================
template <typename T> void _print(const vector<T> &v) {
    _print_start();
    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        if (i) _print_sep();
        _print(v[i]);
    }
    _print_end();
}
template <typename T> void _print(const vector<vector<T>> &v) {
    _print_start();
    _print_LF();
    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        for (int j = 0; j < static_cast<int>(v[i].size()); ++j) {
            if (j) _print_sep();
            _print(v[i][j]);
        }
        _print_LF();
    }
    _print_end();
}
template <typename T> void _print(const set<T> &v) {
    _print_start();
    int i = 0;
    for (auto &&x : v) {
        if (i++) _print_sep();
        _print(x);
    }
    _print_end();
}
template <typename T> void _print(const multiset<T> &v) {
    _print_start();
    int i = 0;
    for (auto &&x : v) {
        if (i++) _print_sep();
        _print(x);
    }
    _print_end();
}
template <typename T, typename U> void _print(const map<T, U> &v) {
    _print_start();
    int i = 0;
    for (auto &&[k, x] : v) {
        if (i++) _print_sep();
        _print_p_start();
        _print(k);
        _print_sep();
        _print(x);
        _print_p_end();
    }
    _print_end();
}
// =====================================
// stack queue priority_queue deque
// =====================================
template <typename T> void _print(const stack<T> &v) {
    auto x = v;
    _print_start();
    int i = 0;
    while (!x.empty()) {
        if (i++) _print_sep();
        _print(x.top());
        x.pop();
    }
    _print_end();
}
template <typename T> void _print(const queue<T> &v) {
    auto x = v;
    _print_start();
    int i = 0;
    while (!x.empty()) {
        if (i++) _print_sep();
        _print(x.front());
        x.pop();
    }
    _print_end();
}
template <typename T> void _print(const priority_queue<T> &v) {
    auto x = v;
    _print_start();
    int i = 0;
    while (!x.empty()) {
        if (i++) _print_sep();
        _print(x.top());
        x.pop();
    }
    _print_end();
}
template <typename T> void _print(const deque<T> &v) {
    auto x = v;
    _print_start();
    int i = 0;
    while (!x.empty()) {
        if (i++) _print_sep();
        _print(x.front());
        x.pop_front();
    }
    _print_end();
}
// =====================================
// base
// =====================================
template <typename T> void print(const T &v) {
    _print(v);
    _print_LF();
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", print(__VA_ARGS__)
// --- debug_end
// ==========================================================================
// ==========================================================================
