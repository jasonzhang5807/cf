#include <cstdio>
#include <algorithm>
int f[2010],n;
int main(){
        scanf("%d",&n);
        int a[n+5];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
                int t=0;
                for(int j=0;j<i;j++)if(a[j]>=a[i])t=std::max(t,f[j]);
                f[i]=t+1;
        }
        int t=0;
        for(int i=0;i<n;i++)t=std::max(t,f[i]);
        printf("%d",t);
        return 0;
}
