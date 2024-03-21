#include <bits/stdc++.h>
using namespace std;
/**
 * 文字列左埋め
 */
string lpad(const string &S, const int &size, const char &ch) {
    int N = S.size();
    if (N >= size) return S;
    return string(size - N, ch) + S;
}
