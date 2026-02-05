#include <cstdio>
#include <algorithm>
int f[1010];
int main(){
        int n,c;
        scanf("%d%d",&n,&c);
        int p[n+5];
        for(int i=1;i<=n;i++)scanf("%d",&p[i]);
        for(int i=1;i<=n;i++){
                int t=p[i];
                for(int j=1;j<i;j++)
                        t=std::max(t,f[j]+p[i-j]-c);
                f[i]=t;
        }
        printf("%d",f[n]);
        return 0;
}
