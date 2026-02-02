#include <cstdio>
#include <algorithm>
struct city{int num,y,p,dat;};
bool cmp1(const city xx,const city yy){
        if(xx.p==yy.p) return xx.y<yy.y;
        else return xx.p<yy.p;
}
bool cmp2(const city x,const city y){return x.num<y.num;}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
        int n,m;
        scanf("%d%d",&n,&m);
        city a[100010];
        for(int i=0;i<m;i++){
                a[i].num=i;
                scanf("%d%d",&a[i].p,&a[i].y);
        }
        std::sort(a,a+m,cmp1);
        int currentp=a[0].p;
        int usep=1;
        a[0].dat=usep;
        for(int i=1;i<m;i++){
                if(a[i].p == currentp){
                        usep++;
                        a[i].dat=usep;
                }
                else {currentp=a[i].p; usep=1; a[i].dat=1;}
        }
        std::sort(a,a+m,cmp2);
        for(int i=0;i<m;i++) printf("%06d%06d\n",a[i].p,a[i].dat);
        return 0;
}
