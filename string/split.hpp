#include <bits/stdc++.h>
using namespace std;
/**
 * 文字列をcharで分割
 */
vector<string> split(const string &S, const char &c) {
    vector<string> res;
    string t = "";
    for (char v : S) {
        if (v == c) {
            res.emplace_back(t);
            t.clear();
        } else {
            t += v;
        }
    }
    res.emplace_back(t);
    return res;
}
