#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int n, k, x[100010], min_time = 2*1e9;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    for (int i = 0; i <= n - k; i++) {
        int left = x[i], right = x[i + k - 1];
        if (right <= 0) min_time = min(min_time, abs(left));
        else if (left >= 0) min_time = min(min_time, right);
        else min_time = min(min_time, abs(left)<=right ? 2*abs(left)+right : 2*right+abs(left));
    }
    printf("%d\n", min_time);
    return 0;
}
