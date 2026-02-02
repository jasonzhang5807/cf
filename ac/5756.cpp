#include <bits/stdc++.h>
using namespace std;
vector<int> g[10010];
bool d[10010],l[10010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back(b);
		g[b].push_back(a);
		d[a]^=1;
		d[b]^=1;
		if(c%2==1)l[a]^=1,l[b]^=1;
	}
	int q;
	cin>>q;
	while(q--){
		int ipt,o1=0,o2=0;
		scanf("%d",&ipt);
		for(auto x:g[ipt]){
			if(d[x])o1++;
			if(l[x])o2++;
		}
		printf("%d %d\n",o1,o2);
	}
	return 0;
}
