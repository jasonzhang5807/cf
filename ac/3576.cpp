#include <cstdio>
int main(){
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
        int n;
        scanf("%d",&n);
        if(n<=3){
                printf("No");
                return 0;
        }
        for(int cake=0;cake<=14;cake++){
                if((n-cake*7)%4==0&&n>=cake*7){
                        printf("Yes");
                        return 0;
                }
        }
        printf("No");
        return 0;
}
