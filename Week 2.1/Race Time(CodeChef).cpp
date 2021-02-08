#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int s[N], d[N], n, k;

double f(double t) {
    double mn = 1.0 / 0, mx = -1.0 / 0;
    for (int i = 0; i < n; ++i) {
        double cur = d[i] + (s[i] * t);
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    return mx - mn;
}

double ts() {
    double lo = 0, sz = k;
    for (; sz > 1e-20; sz *= 2.0 / 3){
        double a = lo + sz / 3 , b = a + sz / 3;
        if(f(a) > f(b)) lo = a;
    }
    return f(lo);
}


int main() {

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", s + i, d + i);
    }
    printf("%.6f\n" , ts());


    return 0;
}




