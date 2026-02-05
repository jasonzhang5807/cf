#include <cstdio>
#include <algorithm>
#include <cmath>
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
        int n,t,a,h,ans;
        double anscha=2000000000.0;
        scanf("%d%d%d",&n,&t,&a);
        for(int i=1;i<=n;i++){
                scanf("%d",&h);
                double tem=0.006*h-t;
                if(anscha>std::abs(a+tem)) {ans=i; anscha=std::abs(a+tem);}
        }
        printf("%d",ans);
        return 0;
}
