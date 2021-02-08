#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int radii[N] , f , n;
double hi;


bool isValid(double x){
    int cnt = 0;
    for(int i = 0 ; i < n ; ++i)
        cnt += (M_PI * radii[i] * radii[i]) / x;

    return (cnt > f);
}


double bs(){
    double lo = 0 , sz = hi;
    for(sz *= 0.5 ; sz > 1e-9 ; sz *= 0.5){
        if(isValid(lo + sz))
            lo += sz;
    }
    return lo;
}



int main() {

    int tc;
    scanf("%d" , &tc);
    while(tc--){
        scanf("%d %d" , &n , &f);
        for(int i = 0 ; i < n ; ++i){
            scanf("%d", radii + i);
            hi = max(hi , M_PI * radii[i] * radii[i]);
        }
        printf("%.4f\n" , bs());
    }



    return 0;
}




