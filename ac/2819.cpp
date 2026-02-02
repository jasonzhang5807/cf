#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
vector<int> g[maxn];
int rd[maxn];
bool vis[maxn];
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		++rd[v];
	}
    int cnt=0;
	while(1){
        if(cnt==n)return 0;
		bool flag=false;
		for(int i=1;i<=n;++i){
			if(!rd[i]&&!vis[i]){
				flag=1;
                ++cnt;
				vis[i]=1;
				printf("%d ",i);
				for(int v:g[i])--rd[v];
			}
		}
		if(!flag){
			cout<<-1;
			return 0;
		}
	}
	return 0;
}
