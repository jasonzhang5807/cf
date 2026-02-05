#include <bits/stdc++.h>
#define maxn 60010
int dis[maxn],x=1,y=1;
struct node{int v,w;};
std::vector<node>g[maxn];
void add(int u,int v,int w){g[u].push_back({v,w});g[v].push_back({u,w});}
void dfs(int u,int fa,int w){
        dis[u]=dis[fa]+w;
        for(auto nxt:g[u])if(nxt.v!=fa)dfs(nxt.v,u,nxt.w);
}
int main(){
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
                int u,v,w;
                scanf("%d%d%d",&u,&v,&w);
                add(u,v,w);
        }
        dfs(1,0,0);
        for(int i=2;i<=n;i++)if(dis[i]>dis[x])x=i;
        dfs(x,0,0);
        for(int i=2;i<=n;i++)if(dis[i]>dis[y])y=i;
        printf("%d",dis[y]);
        return 0;
}
