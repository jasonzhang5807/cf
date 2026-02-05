#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N][N];
int dp[N];
int main()
{
	freopen("credit.in", "r", stdin);
	freopen("credit.out", "w", stdout);
    int n,m;
    while (scanf("%d%d",&n,&m)==2&&n&&m) {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=n;++i)
            for (int j=m;j>=1;--j)
                for (int k=1;k<=j;++k)
                    dp[j]=max(dp[j],dp[j-k]+a[i][k]);
        printf("%d\n",dp[m]);
    }
    return 0;
}
