/*
    TASK: fence
    LANG: C++14
 */


#include <bits/stdc++.h>

using namespace std;


Problem : (Fence - USACO)
link : https://t...content-available-to-author-only...o.org/usacoprob2?a=MS5hO1taHxi&S=fence


const int N = 2e5 + 10, M = 2 * N;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int head[N], nxt[M], to[M], n, ne, vis[M], vid;

const int E = 1024 + 5;

int U[E], V[E], I[E], res[M], resSize;
bool isOdd[N];

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
    for (int &e = head[u]; ~e; ) {
        int x = e;
        e = nxt[e];
        if (vis[x])
            continue;
        vis[x ^ 1] = 1;
        int v = to[x];
        Euler(v);
    }

    res[resSize++] = u;

}


int main() {
    freopen("fence.in" , "r" , stdin);
    freopen("fence.out" , "w" , stdout);

    int m;
    n = 501;
    init();
    scanf("%d", &m);
    int mn = 501;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        isOdd[a] ^= 1;
        isOdd[b] ^= 1;
        U[i] = min(a, b);
        mn = min(mn, U[i]);
        V[i] = max(a, b);
        I[i] = i;
    }

    sort(I, I + m, [](int a, int b) {
        return tie(U[a], V[a]) < tie(U[b], V[b]);
    });

    for (int i = m - 1; i >= 0; --i)
        addBiEdge(U[I[i]], V[I[i]]);


    int cntOdd = count(isOdd, isOdd + 501, 1);
    if (cntOdd > 2) return puts("-1"), 0;

    int st = mn;
    if (cntOdd) st = find(isOdd, isOdd + 501, 1) - isOdd;
    resSize = 0;
    Euler(st);
//    printf("%d\n" , resSize);
    if (resSize - 1 != m)
        return puts("-1"), 0;

    for (int i = resSize - 1; i >= 0; i--)
        printf("%d\n", res[i]);


    return 0;
}
