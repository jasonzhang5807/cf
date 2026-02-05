#include <bits/stdc++.h>
using namespace std;
long long a[32],f[10010];
int main(){
    long long n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    f[0]=1;
    for(int j=0;j<n;++j)
        for(int i=1;i<=c;++i)
            if(a[j]<=i)f[i]+=f[i-a[j]];
    printf("%lld",f[c]);
    return 0;
}
