#include <cstdio>
#include <algorithm>
#include <cstring>
int l1,s1[100010],dp[100010],g[100010];
int find(int x){
    int l=1,r=l1,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(g[mid]<x){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    scanf("%d",&l1);
    memset(g,0x3f,sizeof(g));
    g[0]=0;
    for(int i=1;i<=l1;i++)scanf("%d",&s1[i]);
    for(int i=1;i<=l1;i++){
        dp[i]=find(s1[i])+1;
        if(s1[i]<g[dp[i]]){
            g[dp[i]]=s1[i];
        }
    }
    int ans=0;
    for(int i=1;i<=l1;i++){
        ans=std::max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}
