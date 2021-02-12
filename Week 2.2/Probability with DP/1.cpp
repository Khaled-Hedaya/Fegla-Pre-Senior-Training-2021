//Problem :https://v...content-available-to-author-only...e.net/problem/TopCoder-4450

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
double mem[20001][201];
int vis[20001][201], vid;

double dp(int remScr, int remT, const vector<int> &A) {
    if (remScr < 0) return 0;
    if (remT == 0) return remScr == 0;
    double &ret = mem[remScr][remT];
    if (vis[remScr][remT] == vid) return ret;
    vis[remScr][remT] = vid;
    ret = 0;
    for (int i = 0; i < 6; ++i) {
        ret += 1.0 / 6 * dp(remScr - A[i], remT - 1, A);
    }
    return ret;
}

double aprob[20001], bprob[20001];

class DiceThrows {
public:
    double winProbability(int numDiceA, vector<int> sidesA, int numDiceB, vector<int> sidesB) {
        vid++;
        sort(sidesA.begin(), sidesA.end());
        sort(sidesB.begin(), sidesB.end());
        for (int i = 0; i <= sidesA.back() * numDiceA; ++i)
            aprob[i] = dp(i, numDiceA, sidesA);
        vid++;
        for (int i = 0; i <= sidesB.back() * numDiceB; ++i)
            bprob[i] = dp(i, numDiceB, sidesB);
        double ret = 0;
        for (int i = 0; i <= sidesA.back() * numDiceA; ++i)
            for (int j = 0; j < i; ++j) {
                ret += aprob[i] * bprob[j];
            }
        return ret;
    }
};
