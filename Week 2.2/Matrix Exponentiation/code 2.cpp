// Fast power
#include <bits/stdc++.h>
#include <ext/numeric>
#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;

int fastPower(int x, int p, int mod) {
    if (!p) return 1;
    int y = fastPower(x, p >> 1, mod);
    y = (1ll * y * y) % mod;
    if (p & 1) y = (1ll * x * y) % mod;
    return y;
}

ll fastMul(ll x, ll p, ll mod) {
    if (!p) return 0;
    ll y = fastMul(x, p >> 1, mod);
    y = (y + y) % mod;
    if (p & 1) y = (x + y) % mod;
    return y;
}

int iterativeFastPower(int x, int p, int mod) {
    int ret = 1;
    while (p) {
        if (p & 1)
            ret = (1ll * ret * x) % mod;
        x = (1ll * x * x) % mod;
        p >>= 1;
    }
    return ret;
}

struct multiply {
    int mod;

    multiply(int m) {
        mod = m;
    }

    int operator()(int a, int b) {
        return (1ll * a * b) % mod;
    }

};

int identity_element(const multiply &x) {
    return 1;
}

typedef vector<vector<int>> vvi;

struct matrixMultiply {
    int n;

    matrixMultiply(int x) {
        n = x;
    }

    vvi operator()(const vvi &a, const vvi &b) {
        vvi ret(a.size(), vector<int>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    ret[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return ret;
    }
};
vvi identity_element(const matrixMultiply &x) {
    vvi ret(x.n,vector<int>(x.n));
    for (int i = 0; i < x.n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}
int main() {
    matrixMultiply m(2);
   vvi a = {{0,1},{1,1}} , b ={{0},{1}};
    for (int i = 0; i < 10; ++i) {
        vvi x = m(power(a,i,m),b);
        cout<<x[0][0]<<endl;
    }
    return 0;
}
