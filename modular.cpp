#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
template <int MOD=1000000007>
struct Modular { /* {{{ */
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }

    friend Modular inverse(Modular b, long long m = MOD) {
        long long u = 0, v = 1, a = b.value;
        while (a != 0) {
            long long t = m / a;
            m -= t * a; swap(a, m);
            u -= t * v; swap(u, v);
        }
        return Modular(u);
    }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
}; /* }}} */
using mint = Modular<M>;

vector<mint> fac, inv;
void initfac(int _n) { /* {{{ */
    fac.resize(_n, 1);
    inv.resize(_n, 1);
    for (int i = 1; i < _n; ++i) fac[i] = i * fac[i-1];
    inv[_n-1] = mint(1, fac[_n-1].value);
    for (int i = _n-2; i >= 0; --i) inv[i] = (i+1) * inv[i+1];
}

mint ncr(int _n, int _r) {
    if (_r < 0 || _r > _n) return 0;
    return fac[_n] * inv[_r] * inv[_n-_r];
}

mint npr(int _n, int _r) {
    if (_r < 0 || _r > _n) return 0;
    return fac[_n] * inv[_n-_r];
} /* }}} */

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    initfac(3e5);

}
