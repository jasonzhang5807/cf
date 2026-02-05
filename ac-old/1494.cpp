#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
long long p(int x){
        if(x==0)return 1;
        return 10*p(x-1);
}
int n,m;
long long f[15][10],str;
long long solve(long long str,int mul){
        if(mul==0) return str;
        if(mul>int(log10(str))) return 0;
        long long t=0;
        for(int i=1;i<=n-mul;i++)t=std::max(t,solve(str/p(i),mul-1)*(str%p(i)));
        return t;
}
int main(){
        scanf("%d%d%lld",&n,&m,&str);
        printf("%lld",solve(str,m));
        return 0;
}
