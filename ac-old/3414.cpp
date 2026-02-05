#include <cstdio>
int n,cnt[60010];
int main(){
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
                int a,b;
                scanf("%d%d",&a,&b);
                cnt[a]++;cnt[b]++;
        }
        for(int i=1;i<=n;i++)printf("%d ",cnt[i]-((i==1)?0:1));
        return 0;
}
