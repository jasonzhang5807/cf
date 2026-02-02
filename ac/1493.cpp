#include <cstdio>
#include <algorithm>
#include <cstring>
int main(){
        int n,a[105][105];
        memset(a,0x3f,sizeof(a));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
        a[0][1]=0;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        a[i][j]+=std::min(a[i-1][j],a[i][j-1]);
        printf("%d",a[n][n]);
        return 0;
}
