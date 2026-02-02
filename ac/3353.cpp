#include <cstring>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
const int INF=0x3f3f3f3f;
typedef std::pair<int,int> pii;
int n,m,s,t;
int main(){
	scanf("%d%d",&n,&m);
	int T,rxa,rxc,rya,ryc,rp;
	int d[n+1];
	bool vis[n+1];
	std::vector<std::vector<pii>> g(n+1);
	scanf("%d%d%d%d%d%d",&T,&rxa,&rxc,&rya,&ryc,&rp);
	m-=T;
	int x,y,a,b;
	for(int i=1;i<=T;i++){
		x=(1ll*x*rxa+rxc)%rp;
		y=(1ll*y*rya+ryc)%rp;
		a=std::min(x%n+1,y%n+1);
		b=std::max(y%n+1,y%n+1);
		g[a].push_back(std::make_pair(b,100000000-100*a));
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(std::make_pair(v,w));
	}
	s=1,t=n;
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	std::priority_queue<pii> pq;
	d[s]=0;
	pq.push(std::make_pair(0,s));
	while(!pq.empty()){
		pii p=pq.top();pq.pop();
		int u=p.second;
		if(u==n) break;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(!vis[v]&&d[u]+w<d[v]){
				d[v]=d[u]+w;
				pq.push(std::make_pair(-d[v],v));
			}
		}
	}
	printf("%d",((d[t]==0x3f3f3f3f)?-1:d[t]));
	return 0;
}
