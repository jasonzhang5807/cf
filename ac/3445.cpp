#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 210
int f[N][N],n;
char kh[N];
int main(){
        scanf("%s",kh+1);
        kh[0]='%';
        n=strlen(kh)-1;
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=n;i++)f[i][i]=1;
        for(int l=2;l<=n;l++){
                for(int i=1,j=i+l-1;j<=n;i++,j++){
                        if(kh[i]=='('&&kh[j]==')'||kh[i]=='['&&kh[j]==']'){
                                if(l==2)f[i][j]=0;
                                else f[i][j]=std::min(f[i][j],f[i+1][j-1]);
                        }
                        for(int k=i;k<j;k++)f[i][j]=std::min(f[i][j],f[i][k]+f[k+1][j]);
                }
        }
        printf("%d",f[1][n]);
        return 0;
}
