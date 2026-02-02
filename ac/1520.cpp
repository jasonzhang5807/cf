#include <cstdio>
#include <algorithm>
int bp[1010][1010];
int main(){
        int v,w,n,vi,wi,ti;
        scanf("%d%d%d",&v,&w,&n);
        while(n--){
                scanf("%d%d%d",&vi,&wi,&ti);
                for(int i=v;i>=vi;i--) for(int j=w;j>=wi;j--) bp[i][j]=std::max(bp[i][j],bp[i-vi][j-wi]+ti);
        }
        printf("%d",bp[v][w]);
        return 0;
}
