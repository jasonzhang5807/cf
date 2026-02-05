#include <bits/stdc++.h>
#include <stdlib.h>
#define maxn 1000010
using namespace std;
set<int> poi;
int fa[maxn],rnk[maxn];
int f(int x){
	if(x!=fa[x])fa[x]=f(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	x=f(x),y=f(y);
	if(x==y){
		cout<<"No";
		exit(0);
	}
	if(rnk[x]<rnk[y])fa[x]=y;
	else fa[y]=x;
	if(rnk[x]==rnk[y])++rnk[y];
}
int main(){
	int u,v;
	for(int i=1;i<=1000000;++i)fa[i]=i;
	while(scanf("%d%d",&u,&v)){
		if(!u&&!v)break;
        poi.insert(u);
        poi.insert(v);
		merge(u,v);
	}
    int cf=-1;
	for(int u:poi){
        if(cf==-1)cf=f(u);
        else if(f(u)!=cf){cout<<"No";return 0;}
    }
	cout<<"Yes";
	return 0;
}
