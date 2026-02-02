#include <cstdio>
int solve(int x,int y){ return x>y ? x-y : y-x;}
int main(){
        freopen("b.in","r",stdin);
        freopen("b.out","w",stdout);
        int a[3],b[3],max=0;
        for(int i=0;i<3;i++) scanf("%d",&a[i]);
        b[0]=solve(a[0],a[1]);
        b[1]=solve(a[1],a[2]);
        b[2]=solve(a[2],a[0]);
        for(int i=0;i<3;i++) max=b[i]>max ? b[i] : max;
        printf("%d",b[0]+b[1]+b[2]-max);
        return 0;
}
