#include <bits/stdc++.h>
using namespace std;
/**
 * 三角形の面積
 * @brief 3頂点の座標で計算
 * @brief 原点スライド後に|x2y1 - y2x1| / 2
 */
template <typename T> double triangle(T x1, T y1, T x2, T y2, T x3, T y3) {
    return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;
}
