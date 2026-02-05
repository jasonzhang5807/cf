#include <bits/stdc++.h>
#define maxn 2025
using namespace std;
int n;
int fa[maxn];
int dfn[maxn];
int low[maxn];
int idx=0;
vector<int> g[maxn];
bool ap[maxn];
void cls(){
    memset(fa,0,sizeof(fa));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    idx=0;
    for(int i=0;i<maxn;++i)g[i].clear();
    memset(ap,0,sizeof(ap));
}
void tarjan(int u){
    int ch=0;
    dfn[u]=low[u]=++idx;
    for(auto e=g[u].begin();e<g[u].end();++e){
        int v=*e;
        if(!dfn[v]){
            ++ch;fa[v]=u;tarjan(v);low[u]=min(low[u],low[v]);
            if(!fa[u]&&ch>1||(fa[u]&&low[v]>=dfn[u]))ap[u]=true;
        }
        else if(v!=fa[u])low[u]=min(low[u],dfn[v]);
    }
}
int main(){
    int u,t,v;
    while(scanf("%d",&n)){
        cls();
        if(!n)break;
        while(scanf("%d",&u)){
            if(!u)break;
            scanf("%d",&t);
            while(t--){
                scanf("%d",&v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        for(int i=1;i<=n;++i)tarjan(i);
        int ans=0;
        for(int i=1;i<=n;++i)if(ap[i])++ans;
        printf("%d\n",ans);
    }
    return 0;
}
