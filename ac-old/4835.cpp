#include <bits/stdc++.h>
using namespace std;
int f[25][100010];
int main(){
	int n,m;
	cin>>n>>m;
	if(n>20){
		cout<<ceil(log2(m));
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int k=1;k<=m;++k){
			f[i][k]=f[i-1][k-1]+f[i][k-1]+1;
			if(f[i][k]>100010)break;
		}
	for(int i=1;i<=m;++i)
		if(f[n][i]>=m){
			cout<<i;
			return 0;
		}
	return 0;
}
