#include <cstdio>
int k,n,ans;
int a[15][25];
int lb(int x,int y){
        int poix,poiy;
        bool qk[k+10];
        for(int i=0;i<k;i++){
                for(int j=0;j<n;j++){
                        if(a[i][j]==x) poix=j;
                        if(a[i][j]==y) poiy=j;
                }
                qk[i]=poix<poiy;
        }
        for(int i=0;i<k-1;i++) if(qk[i]!=qk[i+1]) return 0;
        return 1;
}
int main(){
        scanf("%d%d",&k,&n);
        for(int i=0;i<k;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
        for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) ans+=lb(i,j);
        printf("%d",ans);
        return 0;
}
