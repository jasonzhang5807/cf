#include <bits/stdc++.h>
#define maxn 2510
using namespace std;
int n,m,s,t,d[maxn];
bool vis[maxn];
vector<pair<int,int>> g[maxn];
priority_queue<pair<int,int>> pq;
int main(){
	cin>>n>>m>>s>>t;
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(u==t)break;
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(v.second+d[u]<d[v.first]){
				d[v.first]=d[u]+v.second;
				pq.push({-d[v.first],v.first});
			}
		}
	}
	cout<<d[t];
	return 0;
}
