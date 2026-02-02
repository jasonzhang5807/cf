#include <cstdio>
#include <algorithm>
struct item{int v,p;};
item a[30];
int f[30][30010],n,m;
int main(){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)scanf("%d%d",&a[i].v,&a[i].p);
        for(int i=1;i<=m;i++)
                for(int j=0;j<=n;j++)
                        f[i][j]=std::max(f[i-1][j],a[i].v<=j?(f[i-1][j-a[i].v]+a[i].v*a[i].p):0);
        int ans=0;
        for(int i=0;i<=n;i++)ans=std::max(ans,f[m][i]);
        printf("%d",ans);
        return 0;
}
