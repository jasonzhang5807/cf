#include <cstdio>
#include <algorithm>
int c[110],w[110],f[1010][1010];
int main(){
        int n,v;
        scanf("%d%d",&v,&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&w[i]);
        for(int i=1;i<=n;i++){
                for(int ww=1;ww<c[i];ww++) f[i][ww]=f[i-1][ww];
                for(int ww=c[i];ww<=v;ww++) f[i][ww]=std::max(f[i-1][ww],f[i-1][ww-c[i]]+w[i]);
        }
        printf("%d",f[n][v]);
        return 0;
}
