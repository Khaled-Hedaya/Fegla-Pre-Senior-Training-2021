#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

pair<int, int> dp[100][100];
int vis[100][100], vid, arr[105], n;

int main() {

    while (~scanf("%d", &n)) {
        ++vid;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            dp[i][i] = {0, arr[i]};
        }
        for (int len = 2; len <= n; len++) {
            for (int s = 0; s + len <= n; ++s) {
                int e = s + len - 1;
                auto &ret = dp[s][e];
                ret = {(int) 1e9, -1};
                for (int i = s; i < e; ++i) {
                    auto m1 = dp[s][i];
                    auto m2 = dp[i + 1][e];
                    auto cur = ret;
                    cur.first = m1.first + m2.first + (m1.second * m2.second);
                    cur.second = (m1.second + m2.second) % 100;
                    ret = min(ret, cur);
                }
            }
        }
        printf("%d\n", dp[0][n - 1].first);
    }
    return 0;
}
