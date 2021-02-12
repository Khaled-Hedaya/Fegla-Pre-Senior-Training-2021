
https://v...content-available-to-author-only...e.net/problem/TopCoder-1848
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class BirthdayOdds {
public:
    int minPeople(int mo, int d) {
        double p = mo / 100.0;
        double num = d - 1;
        double cur = 1;
        int ret = 1;
        while (1 - cur < p) {
            cur *= num-- / d;
            ret++;
        }
        return ret;
    }
};
