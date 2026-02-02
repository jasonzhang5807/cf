#include <cstdio>
#include <stack>
int s[25];
void print(int n){
        printf("%d",s[1]);
        for(int i=2;i<=n;i++) printf("+%d",s[i]);
        printf("\n");
}
void dfs(int n,int dep){
        if(n==0){
                print(dep-1);
                return;
        }
        for(int i=s[dep-1];i<=n;i++){
                s[dep]=i;
                dfs(n-i,dep+1);
                //s[dep]=0;
        }
}
int main(){
        int n;
        scanf("%d",&n);
        s[0]=1;
        dfs(n,1);
        return 0;
}
