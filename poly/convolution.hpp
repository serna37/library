#include <bits/stdc++.h>
using namespace std;
/**
 * 畳み込み ナイーブ
 */
template <typename T>
vector<T> convolution(const vector<T> &A, const vector<T> &B) {
    int a = A.size();
    int b = B.size();
    int c = a + b - 1;
    vector<T> C(c);
    for (int i = 0; i < c; ++i) {
        T tmp = 0;
        // Σ 添え字の和がiになる項同士の積
        for (int j = 0; j <= i; ++j) {
            tmp += A[j] * B[i - j];
        }
        C[i] = tmp;
    }
    return C;
}
