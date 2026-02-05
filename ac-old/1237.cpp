#include <cstdio>
#include <algorithm>
struct x{
	int b,f;
	bool operator<(const x &nxt){
		if(f>nxt.f)return true;
		else if(f<nxt.f)return false;
		if(b<nxt.b)return true;
		else return false;
	};
} s[5010];
int f(int c){
	int i=0;
	while(s[i].f>=c)i++;
	return i;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d",&s[i].b,&s[i].f);
	std::sort(s,s+n);
	printf("%d %d\n",s[m*3/2-1].f,f(s[m*3/2-1].f));
	for(int i=0;i<f(s[m*3/2-1].f);i++){
		printf("%d %d\n",s[i].b,s[i].f);
	}
	return 0;
}
