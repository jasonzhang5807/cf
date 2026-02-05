#include <cstdio>
int main(){
        int fib1,fib2,fib3,n,k;
        scanf("%d",&k);
        while(k--){
                fib1=1;
                fib2=1;
                scanf("%d",&n);
                n-=1;
                while(n--){
                        fib3=fib1+fib2;
                        fib3%=1000000007;
                        fib1=fib2;
                        fib2=fib3;
                }
                printf("%d\n",fib1);
        }
        return 0;
}
