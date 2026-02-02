#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	int pw[10];
	cin>>n;
	int a,b,c,d,e;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		pw[i]=a*10000+b*1000+c*100+d*10+e;
	}
	set<int> ans[10];
	set<int> opt;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=10000;j*=10)
			for(int k=1;k<=9;++k){
				int t=pw[i]+k*j;
				if(t/j%10<pw[i]/j%10)t-=j*10;
				ans[i].insert(t);
			}
		for(int j=11;j<=11000;j*=10)
			for(int k=1;k<=9;++k){
				int t=pw[i]+k*j;
				if(t/(j/11)%10<pw[i]/(j/11)%10)t-=j/11*10;
				if(t/(j/11*10)%10<pw[i]/(j/11*10)%10)t-=j/11*100;
				ans[i].insert(t); 
			}
	}
	for(int i=2;i<=n;++i){
		opt.clear();
		set_intersection(ans[1].begin(),ans[1].end(),ans[i].begin(),ans[i].end(),inserter(opt,opt.begin()));
		ans[1]=opt;
	}
	cout<<ans[1].size();
	return 0;
}
