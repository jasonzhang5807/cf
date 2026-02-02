#include <cstdio>
#include <algorithm>
int n,m,map[105][105],ans;
void dfs(int x,int y){
        ans++;map[x][y]=0;
        if(map[x-1][y]==1) dfs(x-1,y);
        if(map[x+1][y]==1) dfs(x+1,y);
        if(map[x][y-1]==1) dfs(x,y-1);
        if(map[x][y+1]==1) dfs(x,y+1);
}
int main(){
        int opt=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&map[i][j]);
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        if(map[i][j]==1){
                                dfs(i,j);
                                opt=std::max(opt,ans);
                                ans=0;
                        }
                }
        }
        printf("%d",opt);
        return 0;
}
