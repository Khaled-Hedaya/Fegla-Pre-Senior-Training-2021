#include <bits/stdc++.h>
//https://v...content-available-to-author-only...e.net/problem/TopCoder-2989
#define endl '\n'
using namespace std;
typedef long long ll;

class QuizShow {
public:
    int wager(vector<int> s, int w1, int w2) {
        int bstScore = 0, cnt = 0;
        for (int w = 0; w <= s[0]; ++w) {
            int wins = 0;
            for (int i = -1; i < 2; i += 2) {
                for (int j = -1; j < 2; j += 2) {
                    for (int k = -1; k < 2; k += 2) {
                        int myscr = s[0] + w * i;
                        int hisscr = s[1] + w1 * j;
                        int herscr = s[2] + w2 * k;
                        wins+=myscr>hisscr&&myscr>herscr;
                    }
                }
            }
            if(wins>cnt)
                cnt = wins , bstScore = w;
        }
        return bstScore;
    }

};
