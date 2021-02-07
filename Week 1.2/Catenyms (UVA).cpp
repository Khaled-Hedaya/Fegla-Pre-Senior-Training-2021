#include <bits/stdc++.h>

using namespace std;

// problem link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1382

const int N = 2e5 + 10, M = 2 * N;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int head[N], nxt[M], to[M], n, ne;

const int E = 1024 + 5;

int res[M], resSize, deg[N], I[1000], lst[N];
char str[1000][21];


void init() {
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t) {
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v) {
    addEdge(u, v);
    addEdge(v, u);
}

void Euler(int u) {
    for (int &e = head[u]; ~e;) {
        int x = e;
        e = nxt[e];
        int v = to[x];
        Euler(v);
        res[resSize++] = x;
    }


}


int main() {
//   freopen("in.txt" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);

    int t, m;
    scanf("%d", &t);
    while (t--) {
        n = 128;
        init();
        fill(deg + 'a', deg + 'z' + 1, 0);
        scanf("%d", &m);

        int st = 'z';
        for (int i = 0; i < m; ++i) {
            scanf("%s", str[i]);
            lst[i] = strlen(str[i]) - 1;
            I[i] = i;
            st = min({st, (int) str[i][0], (int) str[i][lst[i]]});
            deg[str[i][0]]++, deg[str[i][lst[i]]]--;
        }
        sort(I, I + m, [](int a, int b) {
            return strcmp(str[a], str[b]) > 0;
        });

        for (int i = 0; i < m; ++i) {
            int j = I[i];
            addEdge(str[j][0], str[j][lst[j]]);
        }
        bool ok = 1;
        int cnt1 = 0;
        for (int i = 'a'; i <= 'z'; ++i) {
            switch (deg[i]) {
                case 0:
                    break;
                case 1:
                    if (cnt1++) ok = 0;
                    st = i;
                    break;
                case -1:
                    break;
                default:
                    ok = 0;
                    break;
            }
        }
        resSize = 0;
        Euler(st);
        ok &= resSize == m;
        if (ok) {
            for (int i = resSize - 1; i >= 0; --i)
                printf("%s%c", str[I[res[i]]], ".\n"[!i]);

        } else
            puts("***");

    }


    return 0;
}
