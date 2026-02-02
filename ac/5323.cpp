#include <cstdio>
#include <algorithm>
#include <cstring>
#define MOD 9999973
using namespace std;
long long f[105][105][105],n,m;
int c(int x){return (x*(x-1)/2)%MOD;}
int main(){
        f[0][0][0]=1;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++){
                for(int j=0;j<=m;j++){
                        for(int k=0;k<=m-j;k++){
                                f[i][j][k]=f[i-1][j][k];
                                if(k>=1)f[i][j][k]+=f[i-1][j+1][k-1]*(j+1);
                                if(j>=1)f[i][j][k]+=f[i-1][j-1][k]*(m-j-k+1);
                                if(k>=2)f[i][j][k]+=f[i-1][j+2][k-2]*c(j+2);
                                if(k>=1)f[i][j][k]+=f[i-1][j][k-1]*(m-j-k+1)*j;
                                if(j>=2)f[i][j][k]+=f[i-1][j-2][k]*c(m-j-k+2);
                                f[i][j][k]%=MOD;
                        }
                }
        }
//      for(int i=0;i<=n;i++){
//              printf("i=%d:\n",i);
//                for(int j=0;j<=m;j++){
//                        for(int k=0;k<=m;k++)printf("%lld\t",f[i][j][k]);
//                      putchar('\n');
//              }
//      }
//      printf("-----------------\n");
        long long ans=0;
        for(int j=0;j<=m;j++)for(int k=0;k<=m;k++)ans=(ans+f[n][j][k])%MOD;
        printf("%lld\n",ans);
        return 0;
}
