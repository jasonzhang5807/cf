#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int fa[maxn],rnk[maxn],sze[maxn],n,m;
int f(int x){
    if(x!=fa[x])fa[x]=f(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=f(x);
    y=f(y);
    if(x==y)return;
    if(rnk[x]<rnk[y])fa[x]=y,sze[y]+=sze[x],sze[x]=0;
    else fa[y]=x,sze[x]+=sze[y],sze[y]=0;
    if(rnk[x]==rnk[y])++rnk[y];
}
int main(){
    int t,u,v,ans;
    cin>>t;
    while(t--){
        ans=0;
        scanf("%d%d",&n,&m);
        memset(rnk,0,sizeof(rnk));
        for(int i=1;i<=n;++i)fa[i]=i,sze[i]=1;
        while(m--){
            scanf("%d%d",&u,&v);
            merge(u,v);
        }
        for(int i=1;i<=n;++i){
            if(sze[i]>0){
                ans+=(sze[i]+9)/10;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
