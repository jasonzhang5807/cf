#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull p[10086],b=89,sum[1000010];
char s1[10010],s2[1000010];
int main(){
	int k;
	cin>>k;
	p[0]=1;
	for(int i=1;i<10080;i++)p[i]=p[i-1]*b;
	while(k--){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int n=strlen(s1+1),m=strlen(s2+1);
		sum[0]=0;
		for(int i=1;i<=m;++i) sum[i]=sum[i-1]*b+(ull)(s2[i]-64);
		ull s=0;
		for(int i=1;i<=n;++i) s=s*b+(ull)(s1[i]-64);
		int ans=0;
		for(int i=1;i+n<=m+1;++i) {
			if(sum[i+n-1]-sum[i-1]*p[n]==s) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
