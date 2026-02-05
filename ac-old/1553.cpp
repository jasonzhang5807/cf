#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 305
int f[N][N],n,sum[N];
int main(){
        scanf("%d",&n);
        int tmp;
        for(int i=1;i<=n;i++){
                scanf("%d",&tmp);
                sum[i]=sum[i-1]+tmp;
        }
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=n;i++)f[i][i]=0;
        for(int l=2;l<=n;l++){
                for(int i=1,j=i+l-1;j<=n;i++,j++){
                        for(int k=i;k<j;k++){
                                f[i][j]=std::min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
                        }
                }
        }
        printf("%d",f[1][n]);
        return 0;
}
