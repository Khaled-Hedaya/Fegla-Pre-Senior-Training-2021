#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

// Knight moves (UVA)
// problem link : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=380

int vis[8][8], vid;

bool ok(int i, int j) {
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

int bfs(int si, int sj, int ti, int tj) {
    ++vid;
    if (si == ti && sj == tj) return 0;
    queue<pair<int, int> > q;
    q.emplace(si, sj);
    int no_steps = 0;
    while (q.size()) {
        no_steps++;
        int s = q.size();
        while (s--) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            for (int di = -1; di < 2; di += 2) {
                for (int dj = -1; dj < 2; dj += 2) {
                    for (int ii = 1, jj = 2, k = 2; k--; swap(ii, jj)) {
                        int ni = i + (di * ii);
                        int nj = j + (dj * jj);
                        if (!ok(ni, nj) || vis[ni][nj] == vid)
                            continue;
                        if (ni == ti && nj == tj)
                            return no_steps;
                        vis[ni][nj] = vid;
                        q.emplace(ni, nj);
                    }
                }
            }

        }
    }
    return -1;
}


int main() {


    int q, sj, tj;
    char si, ti;
    while (~scanf(" %c%d %c%d", &si, &sj, &ti, &tj)) {
        printf("To get from %c%d to %c%d takes %d knight moves.\n", si, sj, ti, tj,
               bfs(si - 'a', sj - 1, ti - 'a', tj - 1));
    }

    return 0;
}
