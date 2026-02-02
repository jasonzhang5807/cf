#include <cstdio>
#include <cstring>
struct node{long long lft,r,dat;};
node sta[50010];
long long dp[50010],n,l,c[50010],sum[50010],poi=1;
long long w(int i,int j){return dp[i]+(sum[j]-sum[i]+j-i-1-l)*(sum[j]-sum[i]+j-i-1-l);}
long long find(int x){
        int lft=1,r=poi,mid;
        while(lft<=r){
                mid=(lft+r)/2;
                if(sta[mid].lft>x) r=mid-1;
                else if(sta[mid].r<x) lft=mid+1;
                else return sta[mid].dat;
        }
        return sta[mid].dat;
}
int find2(node &st,int i){
        int lft=st.lft,r=st.r,mid;
        while(lft<=r){
                mid=(lft+r)/2;
                if(w(i,mid)<w(st.dat,mid)) r=mid-1;
                else lft=mid+1;
        }
        return lft;
}
int main(){
        //freopen("5.in","r",stdin);
        //freopen("5.ans","w",stdout);
        scanf("%lld%lld",&n,&l);
        for(int i=1;i<=n;i++){
                scanf("%lld",&c[i]);
                sum[i]=sum[i-1]+c[i];
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        sta[poi]=(node){0,n,0};
        for(int i=1;i<=n;i++){
                dp[i]=w(find(i),i);
                while(poi&&w(i,sta[poi].lft)<=w(sta[poi].dat,sta[poi].lft))poi--;
                if(poi){
                        int tmp=find2(sta[poi],i);
                        sta[poi].r=tmp-1;
                        if(tmp<=n)sta[++poi]=(node){tmp,n,i};
                }
                else sta[++poi]=(node){i,n,i};
        }
        printf("%lld",dp[n]);
        return 0;
}
