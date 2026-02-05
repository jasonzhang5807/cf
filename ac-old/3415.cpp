#include <bits/stdc++.h>
#define maxn 60010
std::vector<int>g[maxn];
int ans[maxn][2];
void add(int u,int v){g[u].push_back(v);g[v].push_back(u);}
int dfs(int u,int fa,int dep){
        int subtree=0;
        for(auto v:g[u])if(v!=fa)subtree+=dfs(v,u,dep+1);
        //printf("poi:%d,subtree:%d,depth:%d\n",u,subtree,dep);
        ans[u][0]=subtree;
        ans[u][1]=dep;
        return subtree+1;
}
int main(){
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
                int u,v;
                scanf("%d%d",&u,&v);
                add(u,v);
        }
        dfs(1,0,1);
        for(int i=1;i<=n;i++)printf("%d %d\n",ans[i][0]+1,ans[i][1]);
        return 0;
}
