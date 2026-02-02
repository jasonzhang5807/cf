#include <bits/stdc++.h>
using namespace std;
priority_queue<int> jg;
int n,b,a[210],odd[210];
inline int nabs(int n){return n<0?n:-n;}
int main(){
	cin>>n>>b;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	odd[0]=a[0]%2;
	for(int i=1;i<n;i++)odd[i]=odd[i-1]+a[i]%2;
	for(int i=1;i<n;i++)if(odd[i-1]*2==i)jg.push(nabs(a[i]-a[i-1]));
	int ans=0;
	while(!jg.empty()){
		b+=jg.top();
		if(b>=0)ans++;
		jg.pop();
	}
	cout<<ans;
	return 0;
}
