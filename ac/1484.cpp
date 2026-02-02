#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
int n;
stack<int> sta;
bool ins[maxn];
int dfn[maxn];
int low[maxn];
int idx=0;
vector<int> g[maxn];
vector<int> c[maxn];
int sccnt=0;
set<pair<int,int> > _uni;
vector<int> scc[maxn];
int insc[maxn];
void tarjan(int u){
    dfn[u]=low[u]=++idx;
    ins[u]=1;
    sta.push(u);
    for(auto e=g[u].begin();e<g[u].end();++e){
        int v=*e;
        if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
        else if(ins[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++sccnt;
        int v;
        do{
            v=sta.top();sta.pop();
            ins[v]=0;
            scc[sccnt].push_back(v);
            insc[v]=sccnt;
        }while(v!=u);
    }
}
void solve(){for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);}
int main(){
    cin>>n;
    int v;
    for(int u=1;u<=n;++u){
        while(1){
            scanf("%d",&v);
            if(v==0)break;
            g[u].push_back(v);
        }
    }
    solve();
    for(int u=1;u<=n;++u){
        for(auto v:g[u]){
            if(insc[u]==insc[v])continue;
            _uni.insert({insc[u],insc[v]});
        }
    }
    int ncd=0,ans=-1;
    set<int> tmp;
    for(auto x:_uni)c[x.first].push_back(x.second),tmp.insert(x.second);
    for(int x=1;x<=sccnt;++x)if(c[x].empty())++ncd,ans=x;
    int nrd=sccnt-tmp.size();
    cout<<nrd<<endl<<((sccnt==1)?0:max(ncd,nrd));
    return 0;
}
