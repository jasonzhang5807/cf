#include <cstdio>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <set>
struct p{int x,y,indep;};
std::queue<p> b;
std::set<int> vis;
int n,x,y,map[105][105];
void bfs(int crt,int dep){
        for(int i=1;i<=n;i++) if(map[crt][i]==1&&!vis.count(i)) b.push((p){crt,i,dep});
        vis.insert(crt);
        while(!b.empty()){
                p t=b.front();
                b.pop();
                if(dep<=t.indep&&t.x!=x) dep++;
                //printf("%d->%d,%d;\n",t.x,t.y,dep);
                if(t.y==y){
                        printf("%d",dep);
                        exit(0);
                }
                bfs(t.y,dep);
        }
}
int main(){
        scanf("%d%d%d",&n,&x,&y);
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&map[i][j]);
        if(x==y){
                printf("0");
                exit(0);
        }
        bfs(x,0);
        printf("-1");
        return 0;
}
