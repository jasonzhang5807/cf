#include <bits/stdc++.h>
#define maxn 410
using namespace std;
int nx,ny,vis[maxn],match[maxn];
vector<int> g[maxn];
bool f(int x){
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(!vis[y]){
			vis[y]=1;
			if(match[y]<0||f(match[y])){
				match[y]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	cin>>nx>>ny;
	for(int i=1;i<=nx;++i){
		int m,t;
		scanf("%d",&m);
		while(m--){
			scanf("%d",&t);
			g[i].push_back(t);
		}
	}
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=nx;++i){
		memset(vis,0,sizeof(vis));
		if(f(i))++ans;
	}
	cout<<ans;
	return 0;
}
