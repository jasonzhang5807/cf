#include <cstdio>
#include <stdlib.h>
int n,mk[85];
void dfs(int x){
        for(int f=1,s=f+x+1;s<=2*n;f++,s++){
                if(mk[f]!=0||mk[s]!=0)continue;
                mk[f]=x;mk[s]=x;
                if(x==1){for(int i=1;i<=2*n;i++)printf("%d ",mk[i]);exit(0);}
                dfs(x-1);
                mk[f]=0;mk[s]=0;
        }
}
int main(){
        scanf("%d",&n);
        dfs(n);
        return 0;
}
