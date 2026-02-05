#include <cstdio>
int s[205],k,ans;
void dfs(int n,int dep){
        if(n==0||dep>=k){
                ans++;
                return;
        }
        for(int i=s[dep-1];i<=n/(k-dep+1);i++){
                s[dep]=i;
                dfs(n-i,dep+1);
                //s[dep]=0;
        }
}
int main(){
        int n;
        scanf("%d%d",&n,&k);
        s[0]=1;
        dfs(n,1);
        printf("%d",ans);
        return 0;
}
