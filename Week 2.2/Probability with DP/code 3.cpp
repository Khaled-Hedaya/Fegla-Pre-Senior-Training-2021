
// https://v...content-available-to-author-only...e.net/problem/TopCoder-3510
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

typedef long long ll;
double mem[1001][11];
int vis[1001][11], vid, trgt;

double dp(int n, int nest) {
    if (nest == 1) return trgt < n ? 1.0 / n : 0;
    double &ret = mem[n][nest];
    if (vis[n][nest] == vid) return ret;
    ret = 0;
    vis[n][nest] = vid;
    for (int i = 0; i < n; ++i) {
        ret += 1.0 / n * dp(i, nest - 1);
    }
    return ret;
}

class NestedRandomness {
public:
    double probability(int N, int nestings, int target) {
        trgt = target;
        vid++;
        return dp(N, nestings);
    }
};
