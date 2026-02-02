#include <cstdio>
int n,r,s[10];
bool notin(int x){
        for(int i=0;i<10;i++) if(x==s[i]) return false;
        return true;
}
void dfs(int dep){
        if(dep>=r){
                for(int i=0;i<r;i++) printf("%d ",s[i]);
                putchar('\n');
                return;
        }
        for(int i=1;i<=n;i++) if(notin(i)) s[dep]=i,dfs(dep+1);
        s[dep]=0;
}
int main(){
        scanf("%d%d",&n,&r);
        dfs(0);
        return 0;
}
