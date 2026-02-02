#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int f[1010][32],n,m;
int main(){
	freopen("board.in", "r", stdin);
	freopen("board.out", "w", stdout);
        cin>>n>>m;
        f[0][0]=1;
        for(int i=1;i<=m;++i)
                for(int s=0;s<(1<<n);++s){
                        f[i][s]=f[i-1][~s&(1<<n)-1];
                        for(int k=0;k<n-1;++k)
                                if(!(s&3<<k)){
                                        f[i][s]+=f[i-1][(~s&(1<<n)-1)^(3<<k)];
                                        f[i][s]%=mod;
                                }
                        if(n==4&&!s)f[i][s]+=f[i-1][0],f[i][s]%=mod;
                        if(n==5&&!s)f[i][s]+=((f[i-1][1]+f[i-1][4])%mod+f[i-1][16])%mod,f[i][s]%=mod;
                        if(n==5&&(s==1||s==4||s==16))f[i][s]+=f[i-1][0],f[i][s]%=mod;
                }
        cout<<f[m][0];
        return 0;
}
