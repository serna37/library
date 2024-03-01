#include <bits/stdc++.h>
using namespace std;
/**
 * エラトステネスの篩
 */
template <typename T> vector<bool> eratosthenes(T N) {
    vector<bool> is_P(N + 1, true);
    is_P[0] = is_P[1] = false;
    for (T i = 2; i * i <= N; i++) {
        if (!is_P[i]) continue;
        for (T j = i * i; j <= N; j += i) is_P[j] = false;
    }
    return is_P;
}
// TODO 素数列挙以外も使えるので構造にしたい
// エラトステネスの篩
struct eratosthenes {
  public:
    // 前計算
    //   - O(N log log N)
    eratosthenes(int N) : N(N) {
        D.resize(N+1);
        iota(D.begin(), D.end(), 0);
        for (int p : {2, 3, 5}) {
            for (int i = p*p; i <= N; i += p) { if (D[i] == i) { D[i] = p; } }
        }
        vector<int> inc = {4, 2, 4, 2, 4, 6, 2, 6};
        int p = 7, idx = 0;
        int root = floor(sqrt(N) + 0.5);
        while (p <= root) {
            if (D[p] == p) {
                for (int i = p*p; i <= N; i += p) { if (D[i] == i) { D[i] = p; } }
            }
            p += inc[idx++];
            if (idx == 8) { idx = 0; }
        }
    }

    // 素数判定
    //   - O(1)
    bool is_prime(int x) const {
        assert(1 <= x && x <= N);
        if (x == 1) { return false; }
        return D[x] == x;
    }

    // 素因数分解
    //   - O(log x), 厳密には O(Σi ei)
    vector<pair<int,int>> factorize(int x) const {
        assert(1 <= x && x <= N);
        vector<pair<int,int>> F;
        while (x != 1) {
            int p = D[x];
            int e = 0;
            while (x % p == 0) { x /= p; e++; }
            F.emplace_back(p, e);
        }
        return F;
    }

    // 約数列挙
    //   - O(Πi(1+ei))
    //   - ソートされていないことに注意
    vector<int> calc_divisors(int x) const {
        assert(1 <= x && x <= N);

        int n = 1;  // 約数の個数
        vector<pair<int,int>> F;
        while (x != 1) {
            int p = D[x];
            int e = 0;
            while (x % p == 0) { x /= p; e++; }
            F.emplace_back(p, e);
            n *= (1 + e);
        }

        vector<int> divisors(n,1);
        int sz = 1;  // 現在の約数の個数
        for (const auto& [p, e] : F) {
            for (int i = 0; i < sz * e; i++) {
                divisors[sz + i] = divisors[i] * p;
            }
            sz *= (1 + e);
        }
        return divisors;
    }

    // 最小素因数 (least prime factor)
    //   - O(1)
    int lpf(int x) const { assert(1 <= x && x <= N); return D[x]; }

    // オイラーの φ 関数
    // 1 から x までの整数のうち x と互いに素なものの個数 φ(x)
    //   - O(log x), 厳密には O(Σi ei)
    int euler_phi(int x) const {
        assert(1 <= x && x <= N);
        int res = x;
        while (x != 1) {
            int p = D[x];
            res -= res / p;
            while (x % p == 0) { x /= p; }
        }
        return res;
    }

    // メビウス関数のテーブルを計算する
    //   - O(N)
    vector<int> calc_moebius() const {
        vector<int> moebius(N+1, 0);
        moebius[1] = 1;
        for (int x = 2; x <= N; x++) {
            int y = x / D[x];
            if (D[x] != D[y]) { moebius[x] = -moebius[y]; }
        }
        return moebius;
    }

  private:
    int N;
    vector<int> D;  // 最小素因数 (least prime factor)
};
