#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 305
struct Node{long long dat;int n,m;};
Node f[N][N];
long long jz[N];int n;
int main(){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)scanf("%lld",&jz[i]);
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=n;i++){
                f[i][i].dat=0;
                f[i][i].n=jz[i];
                f[i][i].m=jz[i+1];
        }
        for(int l=2;l<=n;l++){
                for(int i=1,j=i+l-1;j<=n;i++,j++){
                        for(int k=i;k<j;k++){
                                f[i][j].n=f[i][k].n;
                                f[i][j].m=f[k+1][j].m;
                                f[i][j].dat=std::min(f[i][j].dat,f[i][k].dat+f[k+1][j].dat+1LL*f[i][k].n*f[i][k].m*f[k+1][j].m);
                        }
                }
        }
        printf("%lld",f[1][n].dat);
        return 0;
}
