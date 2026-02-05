#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
        freopen("d.in","r",stdin);
        freopen("d.out","w",stdout);
        int n,b;
        long long ans=0;
        scanf("%d",&n);
        int a[n+10],px[n+10];
        for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
                a[i]-=i+1;
                px[i]=a[i];
        }
        sort(px,px+n);
        if(n%2!=0) b=px[n/2];
        else b=int(double(px[n/2-1]+px[n/2])/2+0.5);
        for(int i=0;i<n;i++) ans+=abs(a[i]-b);
        printf("%lld",ans);
        return 0;
}
