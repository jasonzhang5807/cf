#include <cstdio>
#include <algorithm>
int main(){
        int n,sum[100010],t,smin[100010];
        sum[0]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
                scanf("%d",&t);
                sum[i]=sum[i-1]+t;
        }
        //smin[0]=0;
        //smin[1]=sum[1];
        for(int i=0;i<=n;i++)
                smin[i]=std::min(smin[i-1],sum[i]);
        int ans=0x80000000;
        for(int i=1;i<=n;i++)
                ans=std::max(ans,sum[i]-smin[i-1]);
        printf("%d",ans);
        return 0;
}
