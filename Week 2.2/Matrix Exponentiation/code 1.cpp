//https://v...content-available-to-author-only...e.net/problem/SPOJ-SUMSUMS

#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 98765431;
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
                    (ret[i][j] += (1ll*a[i][k] * b[k][j]) % MOD) %= MOD;

                }

            }
        }
        return ret;
    }
};

vvi identity_element(const matrixMultiply &x) {
    vvi ret(x.n, vector<int>(x.n));
    for (int i = 0; i < x.n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}

int n, t, A[(int) 5e4 + 5];

int main() {
   
    scanf("%d%d", &n, &t);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", A + i);
        (sum += A[i]) %= MOD;
    }
    vvi a = {{MOD-1,1},{0,n-1}}, b={{0},{sum}};
    matrixMultiply m(2);
    a = power(a,t,m);
    for (int i = 0; i < n; ++i) {
        b[0][0] = A[i];
        printf("%d\n",m(a,b)[0][0]);
    }
    return 0;
}
