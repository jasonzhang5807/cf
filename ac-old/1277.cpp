#include <cstdio>
int w[10010],ans;
int n,k;
bool solve(int len){
        int v=0;
        for(int i=0;i<n;i++) v+=w[i]/len;
        if(v>=k){
                ans=len;
                return true;
        }
        else return false;
}
int main(){
        double ipt;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%lf",&ipt),w[i]=int(100*ipt);
        int l=0,r=10000000,mid;
        while(1){
                mid=(l+r)/2;
                if(mid==0){
                	printf("0.00");
                	return 0;
                }
                bool t=solve(mid);
                if(l>r) break;
                if(t) l=mid+1;
                else r=mid-1;
        }
        printf("%.2lf",double(ans)/100);
        return 0;
}
