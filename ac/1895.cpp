#include <bits/stdc++.h>
using namespace std;
vector<int> g[10010];
vector<int> c[10010];
unordered_set<int> legal;
int dis[10010];
bool vis[10010];
void dfs(int n){
	vis[n]=true;
	if(!n)return;
	legal.insert(n);
	for(int x:c[n])if(!vis[x])dfs(x);
}
int main(){
	memset(dis,-1,sizeof(dis));
	int s,t,n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		c[b].push_back(a);
	}
	cin>>s>>t;
	dfs(t);
	//for(int x:legal)cout<<x<<",";
	//puts("");
	for(int i=1;i<=n;i++){
		if(!legal.count(i)){
			for(int x:c[i])g[x].clear();
			g[i].clear();
		}
	} 
	queue<pair<int,int>> b;
	b.push({s,0});
	while(!b.empty()){
		auto u=b.front();
		b.pop();
		if(u.first==t){
			cout<<u.second;
			return 0;
		}
		for(auto x:g[u.first]){
			if(dis[x]!=-1)continue;
			b.push({x,u.second+1}),dis[x]=u.second+1;
		}
	}
	printf("-1");
	return 0;
}
