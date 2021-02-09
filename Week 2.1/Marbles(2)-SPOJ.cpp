#include <bits/stdc++.h>
 
using namespace std;
 
 
const int N = 2e5 + 10, OO = 0x3f3f3f3f;
//-- "Ù�Ù�Ù�Ù� Ù�Ù� Ù�Ø³Ø¹Ù� Ù�Ø§Ø¨Ø¯ Ù�ØµÙ� .. Ù�Ù�Ù�Ù� Ù�Ù� Ù�Ø³Ø¹Ù� Ù�Ø¶Ù�Ù�Ù� Ù�Ù� Ø§Ù�Ù�ØµÙ�Ù�" --//
 
typedef long long ll;
 
ll fun(int n) {
    return roundl(sqrt(2 * M_PI * n) * pow(n / exp(1), n));
}
 
ll mem[20][20];
 
ll ncr(int n, int r) {
    if (!r or n == 1) return 1;
    if (n < r) return 0;
    ll &ret = mem[n][r];
    if (~ret) return ret;
    return ret = (ncr(n - 1, r - 1) + ncr(n - 1, r));
}
 
unsigned long long ncr2(int n, int r) {
    if (n == r) return 1;
    if (n < r) return 0;
    return ncr2(n - 1, r) * n / (n - r);
}
 
 
int main() {
 
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", ncr2(a - 1, b - 1));
    }
 
 
    return 0;
}
