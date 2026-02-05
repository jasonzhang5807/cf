#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int a[maxn][maxn];
int dp[maxn][maxn][2];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)dp[n][i][0]=a[n][i],dp[n][i][1]=dp[n][i][0]<<1;
    for(int i=n-1;i>=1;--i){
        for(int j=1;j<=i;j++){
            dp[i][j][0]=max(dp[i+1][j][0],dp[i+1][j+1][0])+a[i][j];
            dp[i][j][1]=max({dp[i+1][j][0]+(a[i][j]<<1),dp[i+1][j+1][0]+(a[i][j]<<1),dp[i+1][j][1]+a[i][j],dp[i+1][j+1][1]+a[i][j]});
        }
    }
    cout<<max(dp[1][1][1],dp[1][1][0]+a[1][1]);
    return 0;
}
