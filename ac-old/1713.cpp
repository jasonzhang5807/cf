#include <cstdio>
void solve(int n){
        if(n==1){
                printf("I hate it");
                return;
        }
        if(n%2==0)printf("I love that ");
        else printf("I hate that ");
        solve(n-1);
}
int main(){
        int n;
        scanf("%d",&n);
        solve(n);
        return 0;
}
