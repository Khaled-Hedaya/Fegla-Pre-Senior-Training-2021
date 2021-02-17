#include <bits/stdc++.h>
//https://v...content-available-to-author-only...e.net/problem/TopCoder-12964
#define endl '\n'
using namespace std;
string s;
double mem[5001][5001];

double dp(int st, int en) {
    if (en <= st) return 1;
    double &ret = mem[st][en];
    if (ret == ret)
        return ret;
    bool cnt = (s[st] == '?') || (s[en] == '?');
    if (cnt) {
        ret = 1.0 / 26 * dp(st + 1, en - 1);
    } else {
        ret = s[st] == s[en] ? dp(st + 1, en - 1) : 0;
    }
    return ret;
}

class PalindromicSubstringsDiv1 {
public:

    double expectedPalindromes(vector<string> S1, vector<string> S2) {
        s = "";
        for (auto &str: S1)
            s += str;
        for (auto &str: S2)
            s += str;
        memset(mem,-1,sizeof mem);
        double res = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                res += 1.0*dp(i, j);
            }

        }
        return res;
    }
};
