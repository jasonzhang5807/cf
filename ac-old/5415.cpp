#include <bits/stdc++.h>
using namespace std;
#define maxn 1010
bool vis[maxn];
int msz,hm,n,k;
vector<int> g[maxn];
int dfs(int n){
    if(vis[n])return 0;
    vis[n]=1;
    int ret=1;
    for(auto x:g[n])if(!vis[x])ret+=dfs(x);
    return ret;
}
int main(){
    cin>>n>>k;
    while(k--){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        int r=dfs(i);
        if(r==0)continue;
        msz=max(msz,r);
        ++hm;
    }
    cout<<hm<<" "<<msz;
    return 0;
}
