#include <cstdio>
#include <algorithm>
#include <cstring>
int n,m,ans;
char map[55][55];
void dfs(int x,int y){
        ans++;map[x][y]='L';
        if(map[x-1][y]=='.') dfs(x-1,y);
        if(map[x+1][y]=='.') dfs(x+1,y);
        if(map[x][y-1]=='.') dfs(x,y-1);
        if(map[x][y+1]=='.') dfs(x,y+1);
}
int main(){
        memset(map,'#',sizeof(map));
        int opt=0,x,y;
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){scanf("%c",&map[i][j]);if(map[i][j]=='@')x=i,y=j,map[i][j]='.';}
                getchar();
        }
        dfs(x,y);
        printf("%d",ans);
        return 0;
}
