#include <bits/stdc++.h>
using namespace std;
int fa[200010],rnk[200010];
int fnd(int x){
        if(fa[x]!=x)fa[x]=fnd(fa[x]);
        return fa[x];
}
void merge(int x,int y){
        x=fnd(x),y=fnd(y);
        if(x==y)return;
        if(rnk[x]<rnk[y])fa[x]=y;
        else fa[y]=x;
        if(rnk[x]==rnk[y])++rnk[y];
}
bool check(int x,int y){
        x=fnd(x),y=fnd(y);
        return x==y;
}
int main(){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i)fa[i]=i;
        while(m--){
                int u,v;
                scanf("%d%d",&u,&v);
                merge(u,v);
        }
        int q;
        cin>>q;
        while(q--){
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%s\n",check(x,y)?"Yes":"No");
        }
        return 0;
}
