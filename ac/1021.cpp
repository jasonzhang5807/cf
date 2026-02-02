#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,m,s,d[MAXN],vis[MAXN],t;
vector<pii> g[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	cin>>s>>t;
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	priority_queue<pii> pq;
	d[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		pii p=pq.top();pq.pop();
		int u=p.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(!vis[v]&&d[u]+w<d[v]){
				d[v]=d[u]+w;
				pq.push(make_pair(-d[v],v));
			}
		}
	}
	cout<<((d[t]==0x3f3f3f3f)?-1:d[t]);
	return 0;
}
