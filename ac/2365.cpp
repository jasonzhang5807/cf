#include <bits/stdc++.h>
#define maxn 1510
using namespace std;
vector<int> g[maxn];
bool vis[maxn];
int f[maxn][2];//0不维护，1维护
void dfs(int rt){
    //printf("rt=%d\n",rt);
    vis[rt]=1;
    f[rt][1]=1;
    bool flag=false;
    for(auto x:g[rt]){
        if(!vis[x]){
            dfs(x);
            //printf("back:%d\n",rt);
            f[rt][0]+=f[x][1];
            f[rt][1]+=min(f[x][1],f[x][0]);
            flag=1;
        }
    }
    //if(!flag)f[rt][0]=0x3f3f3f3f;
    //printf("f[%d][0]=%d,f[%d][1]=%d\n",rt,f[rt][0],rt,f[rt][1]);
}
int main(){
    int n,c,u,v;
    cin>>n;
    while(n--){
        scanf("%d%d",&u,&c);
        while(c--){
            scanf("%d",&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(0);
    cout<<min(f[0][0],f[0][1]);
    return 0;
}
