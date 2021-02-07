/*
 TASK: clocks
 LANG: C++11
 */

#include <cstdio>

// problem link : https://train.usaco.org/usacoprob2?a=dY1rzq8j4ad&S=clocks

using namespace std;

const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int vis[1 << 18], vid, sol[3*9];

char *moves[] = {
        "ABDE",
        "ABC",
        "BCEF",
        "ADG",
        "BDEFH",
        "CFI",
        "DEGH",
        "GHI",
        "EFHI"
};

bool dfs(int u , int st , int mx) {
    if (vis[u] == vid) return 0;
    if (!u)
        return 1;
    if (!mx)
        return 0;
    vis[u] = vid;
    for (int i = st; i < sizeof(moves) / sizeof(moves[0]); ++i) {
        int v = u;
        for (char *c = moves[i]; *c; c++) {
            int id = *c - 'A';
            int cur = (v >> (2 * id)) & 3;
            v &= ~(3 << (2 * id));
            cur = ++cur & 3;
            v |= (cur << (2 * id));
        }
        sol[mx - 1] = i + 1;
        if (dfs(v, i ,mx - 1)) return 1;
    }

    return 0;
}


int main() {

//    freopen("clocks.in", "r", stdin);
//    freopen("clocks.out", "w", stdout);
    int u = 0, x;
    for (int i = 0; i < 9; ++i) {
        scanf("%d", &x);
//        x /= 3;
//        x &= 3;
        u |= x << (2 * i);
    }

    int mx;
    for (mx = 0, ++vid; !dfs(u, 0 , mx); mx++, vid++);

//    sort(sol, sol + mx);

    while(mx--)
        printf("%d%c", sol[mx], " \n"[!mx]);


    return 0;
}
