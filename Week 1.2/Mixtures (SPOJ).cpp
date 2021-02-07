#include <bits/stdc++.h>

using namespace std;


//problem link : https://www.spoj.com/problems/MIXTURES/


const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

pair<int, int> dp[100][100];
int vis[100][100], vid, arr[105], n;

pair<int, int> solve(int s, int e) {
    if (s == e) return {0, arr[s]};
    auto &ret = dp[s][e];
    if (vis[s][e] == vid) return ret;
    vis[s][e] = vid;
    ret = {(int) 1e9, -1};
    for (int i = s; i < e; ++i) {
        auto m1 = solve(s, i);
        auto m2 = solve(i + 1, e);
        auto cur = ret;
        cur.first = m1.first + m2.first + (m1.second * m2.second);
        cur.second = (m1.second + m2.second) % 100;
        ret = min(ret , cur);
    }
    return ret;
}


int main() {

    while(~scanf("%d", &n)) {
        ++vid;
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        printf("%d\n", solve(0, n - 1).first);
    }
    return 0;
}
