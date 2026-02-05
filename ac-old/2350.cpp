#include <cstdio>
#include <climits>
int main(){
        int n;
        scanf("%d",&n);
        int f[n+10],c[n+10];
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        f[0]=0;
        for(int j=1;j<=n;j++){
                int max=INT_MIN;
                for(int i=1;i<=j;i++) if(f[j-i]+c[i]>max) max=f[j-i]+c[i];
                f[j]=max;
        }
        int k,x;
        scanf("%d",&k);
        while(k--){
                scanf("%d",&x);
                printf("%d\n",f[x]);
        }
        return 0;
}
