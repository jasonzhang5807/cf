#include <cstdio>
#include <algorithm>
int f[1010];
int main(){
        int n,k;
        scanf("%d",&n);
        int p[n+5];
        for(int i=1;i<=n;i++)scanf("%d",&p[i]);
        scanf("%d",&k);
        for(int i=1;i<=n;i++){
                int t=0;
                for(int j=0;j<i;j++)
                        t=std::max(t,f[j]+p[i-j]);
                f[i]=t;
        }
        while(k--){
                int x;
                scanf("%d",&x);
                printf("%d\n",f[x]);
        }
        return 0;
}
