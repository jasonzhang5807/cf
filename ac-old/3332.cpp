#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
class ft{
public:
	long long val[maxn];
	void cls(){
		memset(val,0,sizeof(val));
	}
	void update(int x,long long v){
		while(x<maxn){
			val[x]+=v;
			x+=x&-x;
		}
	}
	long long query(int x){
		long long ret=0;
		while(x>0){
			ret+=val[x];
			x-=x&-x;
		}
		return ret;
	}
};
ft s,js;
long long a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	s.cls();
	js.cls();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s.update(i,a[i]);
		js.update(i,a[i]*i);
	}
	string buf;
	while(m--){
		cin>>buf;
		if(buf[0]=='Q'){
			int q;
			cin>>q;
			cout<<s.query(q)*(q+1)-js.query(q)<<'\n';
		}
		else{
			int x,y;
			cin>>x>>y; 
			s.update(x,-a[x]+y);
			js.update(x,(-a[x]+y)*x);
			a[x]=y;
		}
	}
	return 0;
}
