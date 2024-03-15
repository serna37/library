#include <bits/stdc++.h>
using namespace std;
/**
 * 文字列をcharで分割
 */
vector<string> split(const string &S, const char &sep) {
    vector<string> res = {""};
    for (auto &&v : S) {
        if (v == sep) {
            res.emplace_back("");
        } else {
            res.back() += v;
        }
    }
    return res;
}
/**
 * 文字列を文字列で分割
 */
vector<string> split(const string &S, const string &sep) {
    vector<string> res = {""};
    for (auto &&v : S) {
        if (count(sep.begin(), sep.end(), v)) {
            res.emplace_back("");
        } else {
            res.back() += v;
        }
    }
    return res;
}
