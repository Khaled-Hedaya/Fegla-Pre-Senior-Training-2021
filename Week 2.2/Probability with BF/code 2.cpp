//https://v...content-available-to-author-only...e.net/problem/TopCoder-3994
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class PipeCuts {
public:
    double probability(vector<int> w, int L) {
        sort(w.begin(), w.end());
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < w.size(); ++i) {
            for (int j = i + 1; j < w.size(); ++j) {
                cnt2++;
                cnt1 += w[i] > L || (w[j] - w[i]) > L || (100 - w[j]) > L;
            }
        }
        return cnt1 * 1.0 / cnt2;
    }
};
