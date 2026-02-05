#include <bits/stdc++.h>
#define maxn 410
using namespace std;
int nx,ny,vis[maxn],match[maxn],k,e[maxn];
unordered_set<int> g[maxn];
bool f(int x){
        for(int y:g[x]){
                if(!vis[y]){
                        vis[y]=1;
                        if(match[y]<0||f(match[y])){
                                match[y]=x;
                                return 1;
                        }
                }
        }
        return 0;
}
int main(){
        int board=1;
        while(cin>>nx>>ny>>k){
                for(int i=1;i<=maxn-5;++i)g[i].clear();
                for(int i=0;i<k;++i){
                        int x,y;
                        scanf("%d%d",&x,&y);
                        g[x].insert(y);
                }
                int ans=0,cnt=0;
                memset(match,-1,sizeof(match));
                for(int i=1;i<=nx;++i){
                        memset(vis,0,sizeof(vis));
                        if(f(i))++ans;
                }
                for(int i=1;i<=ny;++i)e[i]=match[i];
                for(int i=1;i<=ny;++i){
                        if(e[i]>0){
                                int rans=0;
                                g[e[i]].erase(i);
                                memset(match,-1,sizeof(match));
                                for(int j=1;j<=nx;++j){
                                        memset(vis,0,sizeof(vis));
                                        if(f(j))++rans;
                                }
                                if(rans<ans)++cnt;
                                g[e[i]].insert(i);
                        }
                }
                printf("Board %d have %d important blanks for %d chessmen.\n",board,cnt,ans);
                ++board;
        }
        return 0;
}
