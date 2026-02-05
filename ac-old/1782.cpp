#include <bits/stdc++.h>
using namespace std;
int nxt[10000010];
string m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1){
		cin>>m;
		if(m[0]=='.')break;
		m=" "+m;
		int l=m.size()-1;
		nxt[0]=0;
		for(int i=2,j=0;i<=l;++i){
			while(j&&m[i]!=m[j+1])j=nxt[j];
			if(m[i]==m[j+1])++j;
			nxt[i]=j;
		}
		int md=l-nxt[l];
		if(!(l%md))cout<<l/md<<'\n';
		else cout<<1<<'\n';
	}
	return 0;
}
