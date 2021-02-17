
#include <bits/stdc++.h>
/*Problem :https://w...content-available-to-author-only...j.com/problems/CMPLS/*/
#define endl '\n'
using namespace std;

void babageDiffrenceEngine(vector<vector<int>> &def, int m) {
    while (def.back().size() > 1) {
        vector<int> n, &p = def.back();
        for (int i = 0; i < p.size() - 1; ++i) {
            n.emplace_back(p[i + 1] - p[i]);
        }
        def.emplace_back(n);
    }
    def.back().resize(m + 1, def.back().back());
    for (int i = def.size() - 1, j = 1; i > 0; --i, j++) {
        vector<int> &cur = def[i], &prv = def[i - 1];
        for (int k = 0; k < m; ++k) {
            prv.emplace_back(cur[k + j] + prv[k + j]);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int tc, n, m;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        vector<vector<int>> v;
        vector<int> x(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &x[i]);

        v.emplace_back(x);
        babageDiffrenceEngine(v, m);
        for (int j = n; j < v[0].size(); ++j)
            printf("%d%c", v[0][j], " \n"[j == v[0].size() - 1]);

    }
    return 0;
}
