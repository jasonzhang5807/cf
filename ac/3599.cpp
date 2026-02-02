#include <bits/stdc++.h>
using namespace std;
int d[10010];long long l[10010];
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		++d[a],++d[b];
		l[a]+=c;l[b]+=c; 
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",d[i],l[i]);
	return 0;
}
