#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 610
int f[N][N],n,sum[N],a[N];
int main(){
        freopen("stone.in","r",stdin);
        freopen("stone.out","w",stdout);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
                a[i+n]=a[i];
                //sum[i]=sum[i-1]+tmp;
        }
        for(int i=1;i<=2*n;i++)sum[i]=sum[i-1]+a[i];
        //for(int i=n+1;i<=2*n;i++)sum[i]=sum[i-1]+a[i];
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=2*n;i++)f[i][i]=0;
        for(int l=2;l<=n;l++){
                for(int i=1,j=i+l-1;j<=n*2;i++,j++){
                        for(int k=i;k<j;k++){
                                f[i][j]=std::min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
                        }
                }
        }
        int ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++)ans=std::min(ans,f[i][i+n-1]);
        printf("%d",ans);
        return 0;
}
