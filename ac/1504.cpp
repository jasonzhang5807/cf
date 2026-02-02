#include <cstdio>
#include <cstring>
int main(){
        int v,n,a[55];
        scanf("%d%d",&n,&v);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool f[n+5][v+5];
        memset(f,false,sizeof(f));
        for(int j=0;j<=n;j++) f[j][0]=true;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=v;j++){
                        if(a[i]>j) f[i][j]=f[i-1][j];
                        else f[i][j]=f[i-1][j]||f[i-1][j-a[i]];
                }
        }
        for(int j=v;j>=0;j--){
                if(f[n][j]){
                        printf("%d",v-j);
                        return 0;
                }
        }
        return 0;
}
