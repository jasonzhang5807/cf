#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
int n,m,ans=INF;
void dfs(int k,int r,int h,int s,int v){
        if(k==m){
                if(v==0&&ans>s)ans=s;
                return;
        }
        if(v<0||h<=0||r<=0||k>m)return;
        if (v>(r*r*h)*(m-k))return;
        if(s+2*v/r>ans)return;
        for(int tr=1;tr<r;tr++){
                for(int th=1;th<h;th++){
                        if(tr*tr*th>v)continue;
                        dfs(k+1,tr,th,s+2*tr*th,v-tr*tr*th);
                }
        }
}
int main(){
        scanf("%d%d",&n,&m);
        for(int r=m;r*r*m<=n;r++)for(int h=m;r*r*h<=n;h++)dfs(1,r,h,2*r*h+r*r,n-r*r*h);
        printf("%d",ans==0x3f3f3f3f?0:ans);
        return 0;
}
