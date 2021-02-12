//Problem :https://v...content-available-to-author-only...e.net/problem/TopCoder-3509
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long ll;
double mem[101][9][9];
int vis[101][9][9], vid;

double dp(int x, int y, int n) {
    if (x > 8 || y > 8 || x < 1 || y < 1)
        return 0;
    if (n == 0)
        return 1;
    double &ret = mem[n][x][y];
    if (vis[n][x][y] == vid)
        return ret;
    vis[n][x][y] = vid;
    ret = 0;
    for (int i = -1; i < 2; i += 2) {
        for (int j = -1; j < 2; j += 2) {
            int dx = 1, dy = 2;
            for (int k = 0; k < 2; ++k, swap(dx, dy))
                ret += 1.0 / 8 * dp(x + dx * i, y + dy * j, n - 1);
        }
    }
    return ret;
}

class ChessKnight {
public:
    double probability(int x, int y, int n) {
        vid++;
        return dp(x, y, n);
    }
};
