#include <bits/stdc++.h>
#define print128(n) { \
    if (n == 0) { std::cout << '0';} \
    else{ \
    bool neg = false; \
    if (n < 0) { neg = true; n = -n; } \
    std::string s; \
    while (n > 0) { s.push_back('0' + (n % 10)); n /= 10; } \
    if (neg) s.push_back('-'); \
    std::reverse(s.begin(), s.end()); \
    std::cout << s; \
    } \
}
using namespace std;
int main(){
    int tot,n,a[310];
    cin>>tot>>n;
    __int128 dp[1010];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int j=0;j<n;j++)
        for(int i=1;i<=tot;i++)
            if(i-a[j]>=0)dp[i]+=dp[i-a[j]];
    /*for(int i=1;i<tot;i++){
        printf("%d:",i);
        print128(dp[i]);
        puts("");
    }*/
    print128(dp[tot]);
    return 0;
}
