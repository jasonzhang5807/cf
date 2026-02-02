#include <cstdio>
int main(){
        freopen("c.in","r",stdin);
        freopen("c.out","w",stdout);
        int n,t,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&t);
                ans+=t-1;
        }
        printf("%d",ans);
        return 0;
}
