#include <bits/stdc++.h>
#define MAXN 60010
#define LOG 17
using namespace std;
vector<int> g[MAXN];
int dep[MAXN];
int father[MAXN][LOG];
void dfs(int u, int fa) {
    father[u][0] = fa;
    dep[u] = dep[fa]+1;
    for(int k=1;k<LOG;k++) father[u][k] = father[father[u][k-1]][k-1];
    for(int v:g[u]) if (v!=fa) dfs(v,u);
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
	cin>>n;
	n--;
	while(n--){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,1);
	cin>>q; 
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
