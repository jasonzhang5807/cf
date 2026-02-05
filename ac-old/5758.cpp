#include <bits/stdc++.h>
#define MAXN 1010
#define LOG 11
using namespace std;
vector<pair<int,int>> g[MAXN];
int dep[MAXN];
int dist[MAXN];
int father[MAXN][LOG];
void dfs(int u, int fa) {
    father[u][0] = fa;
    dep[u] = dep[fa]+1;
    for(auto p:g[u]){
        if(p.first==fa){
            dist[u]=dist[fa]+p.second;
            break;
        }
    }
    for(int k=1;k<LOG;k++) father[u][k] = father[father[u][k-1]][k-1];
    for(auto v:g[u]) if(v.first!=fa) dfs(v.first,u);
}
int lca(int u, int v) {
    if (dep[u]<dep[v]) swap(u, v);
    for (int k=LOG-1;k>=0;k--)
        if (dep[u]-(1<<k)>=dep[v]) u=father[u][k];
    if (u == v) return u;
    for (int k = LOG-1; k >= 0; k--) 
        if (father[u][k] != father[v][k]) {
            u = father[u][k];
            v = father[v][k];
        }
    return father[u][0];
}
int main(){
	int n,q;
	cin>>n>>q;
	n--;
	while(n--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,1);
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",dist[u]+dist[v]-2*dist[lca(u,v)]);
	}
	return 0;
}
