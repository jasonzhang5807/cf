#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,m,s,d[MAXN][MAXN],vis[MAXN][MAXN],col[MAXN][MAXN];
vector<pair<pii,int>> g[MAXN][MAXN];
const int dx[]={0,0,-1,1,0,-1,-2,-1,0,1,2,1};
const int dy[]={-1,1,0,0,-2,-1,0,1,2,1,0,-1};
const int dw[]={0,0,0,0,2,2,2,2,2,2,2,2};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(col,-1,sizeof(col));
	scanf("%d%d",&m,&n);
	for(int i=1,x,y,c;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		col[x+1][y+1]=c;
	}
	for(int i=2;i<=m+1;i++){
		for(int j=2;j<=m+1;j++){
			if(col[i][j]==-1)continue;
			for(int k=0;k<12;k++){
				if(col[i+dx[k]][j+dy[k]]==-1)continue;
				if(col[i][j]==col[i+dx[k]][j+dy[k]])g[i][j].push_back(make_pair(make_pair(i+dx[k],j+dy[k]),dw[k]));
				else g[i][j].push_back(make_pair(make_pair(i+dx[k],j+dy[k]),dw[k]+1));
			}
		}
	}
	if(col[m+1][m+1]==-1){
		int k=0,i=m+1,j=m+1;
		if(col[i+dx[k]][j+dy[k]]!=-1)g[i+dx[k]][j+dy[k]].push_back(make_pair(make_pair(i,j),2));
		k=2;
		if(col[i+dx[k]][j+dy[k]]!=-1)g[i+dx[k]][j+dy[k]].push_back(make_pair(make_pair(i,j),2));
	}
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<int,pii>> pq;
	d[2][2]=0;
	pq.push(make_pair(0,make_pair(2,2)));
	while(!pq.empty()){
		auto p=pq.top();pq.pop();
		pii u=p.second;
		if(vis[u.first][u.second]) continue;
		vis[u.first][u.second]=1;
		for(int i=0;i<g[u.first][u.second].size();i++){
			pii v=g[u.first][u.second][i].first;
			int w=g[u.first][u.second][i].second;
			if(!vis[v.first][v.second]&&d[u.first][u.second]+w<d[v.first][v.second]){
				d[v.first][v.second]=d[u.first][u.second]+w;
				pq.push(make_pair(-d[v.first][v.second],v));
			}
		}
	}
	cout<<((d[m+1][m+1]==0x3f3f3f3f)?-1:d[m+1][m+1]);
	return 0;
}
