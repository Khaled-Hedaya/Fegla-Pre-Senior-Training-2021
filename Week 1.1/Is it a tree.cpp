#include <bits/stdc++.h>
using namespace std;



//Problem Link : https://w...content-available-to-author-only...j.com/problems/PT07Y/


const int N = 2e5 + 10 , M = 2 * N ;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int head[N] , nxt[M] , to[M] , n , ne , vis[N] , vid;

void init(){
    memset(head , -1 , n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f , int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u , int v){
    addEdge(u , v);
    addEdge(v , u);
}

int dfs(int u){
    if(vis[u] == vid) return 0;
    vis[u] = vid;
    int ret = 1;
    for(int e = head[u] ; e != -1 ; e = nxt[e]){
        int v = to[e];
        ret += dfs(v);
    }

    return ret;
}



int main() {
    int m;
    scanf("%d %d",  &n , &m);
    init();
    ++vid;
    while(m--){
        int a , b;
        scanf("%d %d" , &a , &b);
        addBiEdge(--a , --b);
    }

    if(ne / 2 + 1 != n || dfs(0) != n)
        puts("NO");
    else
        puts("YES");



    return 0;
}
