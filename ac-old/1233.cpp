#include <cstdio>
#include <algorithm>
struct x{
	int b;
	double f;
	bool operator<(const x &nxt){
		if(f>nxt.f)return true;
		return false;
	};
} s[110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d %lf",&s[i].b,&s[i].f);
	std::sort(s,s+n);
	printf("%d %.1lf",s[m-1].b,s[m-1].f);
	return 0;
}
