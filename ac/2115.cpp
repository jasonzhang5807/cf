#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
bool prd[maxn];
int f[maxn];
vector<int> g[maxn];
int eat(int u){
    if(g[u].empty())return 1;
    int ret=0;
    for(int v:g[u]){
        if(!f[v])f[v]=eat(v);
        ret+=f[v];
    }
    return ret;
}
int main(){
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0,u,v;i<m;++i){
        scanf("%d%d",&u,&v);
        g[v].push_back(u);
        prd[u]=1;
    }
    for(int i=1;i<=n;++i)
        if(!prd[i]&&!g[i].empty())
            ans+=eat(i);
    cout<<ans;
    return 0;
}
