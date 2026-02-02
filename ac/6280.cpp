#include <cstdio>
#include <cmath>
int main(){
        freopen("decode.in","r",stdin);
        freopen("decode.out","w",stdout);
        int k,flag=0;
        long long n,e,d,p,q;
        scanf("%d",&k);
        while(k--){
                flag=0;
                scanf("%lld%lld%lld",&n,&d,&e);
                long long  m = n-e*d+2;
                long long  x=m*m-4*n;
                if(x>=0){
                         q = (sqrt(x)+m)/2,p=( -sqrt(x)+m)/2;
                        if(p+q==m&&p*q==n) printf("%lld %lld\n",p,q);
                        else flag = 1;
                }
                else flag = 1;
                if(flag) printf("NO\n");
        }
        return 0;
}
