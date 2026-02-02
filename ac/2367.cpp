#include <bits/stdc++.h>
#define maxn 6010
using namespace std;
vector<int> g[maxn];
int n,f[maxn][2],fa[maxn],hap[maxn];
bool vis[maxn];
void dfs(int u){
        vis[u]=1;
        for(int v:g[u])
                if(!vis[v]){
                        dfs(v);
                        f[u][0]+=max(f[v][0],f[v][1]);
                        f[u][1]+=f[v][0];
                }
        f[u][1]+=hap[u];
}
int main(){
        cin>>n;
        for(int i=1;i<=n;++i)scanf("%d",&hap[i]);
        for(int i=1,u,v;i<n;++i){
                scanf("%d%d",&v,&u);
                if(u==v&&u==0)break;
                fa[v]=u;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        int rt;
        for(int i=1;i<=n;++i)
                if(!fa[i]){
                        rt=i;
                        break;
                }
        dfs(rt);
        cout<<max(f[rt][0],f[rt][1]);
        return 0;
}
