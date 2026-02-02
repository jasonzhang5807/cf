#include <cstdio>
int n,v[1010],f[1010],k,x,ans;
int main(){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d %d",&v[i],&f[i]);
        scanf("%d",&k);
        while(k--){
                ans=0;
                scanf("%d",&x);
                for(int i=1;i<=n;i++) if(f[i]==x) ans++;
                printf("%d\n",ans);
        }
        return 0;
}
