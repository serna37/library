#include <bits/stdc++.h>
using namespace std;
/**
 * modint
 * @brief 演算のみ
 */
template <long long mod> struct modint {
  private:
    long long v;

  public:
    modint() : v(0ll){};
    long long get() {
        return v;
    }
    void operator+=(const long long &a) {
        v += a, v %= mod;
    }
    void operator-=(const long long &a) {
        v -= a, v %= mod;
    }
    void operator*=(const long long &a) {
        v *= a, v %= mod;
    }
};
