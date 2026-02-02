#include <cstdio>
#include <algorithm>
int n,r,map[5010][5010],sum[5010][5010];
int main(){
        scanf("%d%d",&n,&r);
        for(int i=0;i<n;i++){
                int x,y,v;
                scanf("%d%d%d",&x,&y,&v);
                map[x][y]=v;
        }
        sum[0][0]=map[0][0];
        for(int i=1;i<=5000;i++)sum[i][0]=sum[i-1][0]+map[i][0];
        for(int i=1;i<=5000;i++)sum[0][i]=sum[0][i-1]+map[0][i];
        for(int i=1;i<=5000;i++)
                for(int j=1;j<=5000;j++)
                        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+map[i][j];
        int ans=sum[0][0];
        //for(int i=1;i<=5000;i++)ans=std::max(ans,sum[i][0]-sum[i-r])
        for(int i=r-1;i<=5000;i++)
                for(int j=r-1;j<=5000;j++)
                        ans=std::max(ans,sum[i][j]-(i-r<0?0:sum[i-r][j])-(j-r<0?0:sum[i][j-r])+((i-r<0||j-r<0)?0:sum[i-r][j-r]));
        printf("%d",ans);
        return 0;
}
