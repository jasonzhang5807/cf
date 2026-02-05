#include <cstdio>
#include <algorithm>
using namespace std;
struct game{
        int ddl,ddp;
};
bool cmp(game x,game y){return x.ddp>y.ddp;}
bool g[510];
int main(){
        int m,n;
        scanf("%d%d",&m,&n);
        game a[n+10];
        bool flag=false;
        for(int i=0;i<n;i++) scanf("%d",&a[i].ddl);
        for(int i=0;i<n;i++) scanf("%d",&a[i].ddp);
        sort(a,a+n,cmp);
        //
        //for(int i=0;i<n;i++) printf("ddl:%d\tddp:%d\n",a[i].ddl,a[i].ddp);
        for(int i=0;i<n;i++){
                flag=false;
                for(int j=a[i].ddl-1;j>=0;j--){
                        if(g[j]==false){
                                g[j]=true;
                                flag=true;
                                break;
                        }
                }
                if(flag==false) m-=a[i].ddp;
        }
        printf("%d",m);
        return 0;
}
