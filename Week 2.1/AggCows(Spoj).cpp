#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int stoles[N], n, c;

bool isValid(int d) {
    int x = c;
    int lst = -1e9;
    for (int i = 0; i < n; ++i) {
        if (stoles[i] >= lst + d) {
            lst = stoles[i];
            if (--x == 0) return 1;
        }
    }
    return 0;
}

int bs() {
    int lo = 1, hi = (stoles[n - 1] - stoles[0]) / (c - 1), mid;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (isValid(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return hi;
}


int main() {

    int tc;
    scanf("%d" , &tc);
    while(tc--){
        scanf("%d %d" , &n , &c);
        for(int i = 0 ; i < n ; ++i)
            scanf("%d" , stoles + i);

        sort(stoles , stoles + n);

        printf("%d\n" , bs());
    }



    return 0;
}




