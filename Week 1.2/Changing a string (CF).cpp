#include <bits/stdc++.h>

using namespace std;


// problem link :https://codeforces.com/problemset/problem/56/D


const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int dp[1001][1001], vis[1001][1001], vid, n, m;
char s[1001], t[1001];




int solve(int i, int j) {
    if (i == -1) // s is empty
        return j + 1;
    if (j == -1) // t is empty
        return i + 1;

    int &ret = dp[i][j];
    if (vis[i][j] == vid) return ret;
    vis[i][j] = vid;
    ret = solve(i - 1, j - 1) + (s[i] != t[j]); // equal or replace
    ret = min(ret, solve(i - 1, j) + 1); // delete
    ret = min(ret, solve(i, j - 1) + 1); // insert
    return ret;
}


void print(int i, int j) {
    if (j == -1) { // t is empty
        while (~i--)
            printf("DELETE 1\n");

        return;
    }
    if (i == -1) { // s is empty
        do {
            printf("INSERT 1 %c\n", t[j--]);
        } while (~j);
        return;
    }

    int ret = solve(i, j);

    if (ret == solve(i - 1, j - 1) + (s[i] != t[j])) {
        if (s[i] != t[j])
            printf("REPLACE %d %c\n", i + 1, t[j]);
        print(i - 1, j - 1);
        return;
    }
    if (ret == solve(i - 1, j) + 1) {
        printf("DELETE %d\n", i + 1);
        print(i - 1, j);
        return;

    }
    printf("INSERT %d %c\n", i + 2, t[j]);
    print(i, j - 1);

}


int main() {

    scanf("%s %s", s, t);
    ++vid;
    n = strlen(s), m = strlen(t);
    printf("%d\n", solve(n - 1, m - 1));
    print(n - 1, m - 1);

    return 0;
}
