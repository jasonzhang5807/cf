#include <cstdio>
#include <algorithm>
struct path{int t,c;} a[110];
bool cmp(path x,path y){
        if(x.c==y.c) return x.t<y.t;
        return x.c<y.c;
}
int main(){
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
        int n,maxt;
        scanf("%d%d",&n,&maxt);
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].c,&a[i].t);
        std::sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
                if(a[i].t<=maxt){
                        printf("%d",a[i].c);
                        return 0;
                }
        }
        printf("TLE");
        return 0;
}
