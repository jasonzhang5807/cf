#include <bits/stdc++.h>
using namespace std;
int ans[50][50];
int main(){
	int n;
	cin>>n;
	ans[1][n+1>>1]=1;
	int x=1,y=n+1>>1;
	for(int k=2;k<=n*n;++k){
		bool flag=false;
		for(int i=1;i<n;++i)
			if(ans[1][i]==k-1){
				ans[n][i+1]=k;
				x=n,y=i+1;
				flag=1;
				break;
			}
		if(flag) continue;
		for(int i=2;i<=n;++i)
			if(ans[i][n]==k-1){
				ans[i-1][1]=k;
				x=i-1,y=1;
				flag=1;
				break;
			}
		if(flag) continue;
		if(ans[1][n]==k-1){
			ans[2][n]=k;
			x=2,y=n;
			continue;
		}
		if(ans[x-1][y+1])ans[x+1][y]=k,++x;
		else ans[x-1][y+1]=k,--x,++y;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)printf("%d ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}
