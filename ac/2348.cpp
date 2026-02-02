#include <cstdio>
int main(){
        int n;
        long long ans=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) ans*=i,ans%=1000000007;
        printf("%lld",ans);
        return 0;
}
