#include <bits/stdc++.h>
using namespace std;
/**
 * 文字列右埋め
 */
string rpad(const string &S, const int &size, const char &ch) {
    int N = S.size();
    if (N >= size) return S;
    return S + string(size - N, ch);
}
