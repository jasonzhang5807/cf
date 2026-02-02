#include <cstdio>
#include <algorithm>
#include <cstring>
int main(){
        int v,n,a[105],t[105],lt=0;
        scanf("%d%d",&v,&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&t[i]);
        int f[n+5][v+5];
        memset(f,0xff,sizeof(f));
        for(int j=0;j<=n;j++) f[j][0]=0;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=v;j++){
                        if(a[i]>j) f[i][j]=f[i-1][j];
                        else f[i][j]=std::max(f[i-1][j],f[i-1][j-a[i]]+t[i]);
                }
        }
        for(int j=0;j<=v;j++) lt=std::max(lt,f[n][j]);
        printf("%d",lt);
        return 0;
}
