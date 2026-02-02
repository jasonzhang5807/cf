#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[10010];
int dis[10010];
int main(){
	memset(dis,-1,sizeof(dis));
	int s,t,n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	cin>>s>>t;
	deque<pair<int,int>> b;
	b.push_back({s,0});
	while(!b.empty()){
		auto u=b.front();
		b.pop_front();
		if(u.first==t){
			cout<<u.second;
			return 0;
		}
		for(auto x:g[u.first]){
			if(dis[x.first]!=-1)continue;
			if(!x.second)b.push_front({x.first,u.second}),dis[x.first]=u.second;
			else b.push_back({x.first,u.second+1}),dis[x.first]=u.second+1;
		}
	}
	return 0;
}
