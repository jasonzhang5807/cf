#include <bits/stdc++.h>
#define MAXN 510
#define INF 0x3f3f3f3f
using namespace std;
int n,m,s,d[MAXN],u[MAXN],w[MAXN],v[MAXN],t;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	cin>>s>>t;
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	for(int i=1;i<n;++i){
		bool found=false;
		for(int j=1;j<=m;++j){
			if(d[u[j]]<INF&&d[u[j]]+w[i]<d[v[j]]){
				d[v[j]]=d[u[j]]+w[j];  
					found=true;
			}
		}
		if(!found) break;
	}
	for(int j=1;j<=m;++j){
		if(d[u[j]]<INF&&d[u[j]]+w[j]<d[v[j]]){
			printf("-1");
			return 0;
		}
	}
	cout<<((d[t]==0x3f3f3f3f)?-1:d[t]);
	return 0;
}
