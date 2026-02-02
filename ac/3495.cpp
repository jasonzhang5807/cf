#include <cstdio>
#include <climits>
const int MAX_D = 10;
int p[MAX_D], c[MAX_D], s[MAX_D];
int main() {
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int d; long long g;
    scanf("%d %lld", &d, &g);
    for (int i = 0; i < d; i++) {
        scanf("%d %d", &p[i], &c[i]);
        s[i] = (i + 1) * 100;
    }
    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << d); mask++) {
        long long score = 0; int cnt = 0;
        for (int i = 0; i < d; i++) {
            if (mask & (1 << i)) {
                score += 1LL * p[i] * s[i] + c[i];//1LL===(long long)1
                cnt += p[i];
            }
        }
        if (score >= g) {
            ans = (cnt < ans) ? cnt : ans;
            continue;
        }
        for (int i = d - 1; i >= 0; i--) {
            if (!(mask & (1 << i))) {
                int need = (g - score + s[i] - 1) / s[i];
                if (need <= p[i]) {
                    cnt += need;
                    score = g;
                } else {
                    cnt += p[i];
                    score += 1LL * p[i] * s[i];
                }
                break;
            }
        }
        if (score >= g) ans = (cnt < ans) ? cnt : ans;
    }
    printf("%d\n", ans);
    return 0;
}
