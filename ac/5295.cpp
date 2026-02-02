#include <cstdio>
#include <algorithm>
long long f[1010][55];
int main(){
        int n,w,nn,ci,pi;
        long long vi;
        scanf("%d%d%d",&n,&w,&nn);
        while(n--){
                scanf("%d%d",&ci,&pi);
                vi=1LL*ci*pi;
                for(int i=w;i>=ci;i--) for(int j=nn;j>0;j--) f[i][j]=std::max(f[i][j],f[i-ci][j-1]+vi);
        }
        printf("%lld",f[w][nn]);
        return 0;
}
