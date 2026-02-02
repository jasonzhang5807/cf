#include <cstdio>
#include <algorithm>
using namespace std;
struct metal{
        double dj;
        int zj,zl;
};
bool cmp(metal x,metal y){return x.dj>y.dj;}
int main(){
        int k;
        scanf("%d",&k);
        while(k--){
                int w,s;
                double ans=0;
                scanf("%d%d",&w,&s);
                metal n[s+10];
                for(int i=0;i<s;i++){
                        scanf("%d%d",&n[i].zl,&n[i].zj);
                        n[i].dj=double(n[i].zj)/n[i].zl;
                }
                sort(n,n+s,cmp);
                for(int i=0;i<s;i++){
                        if(w==0) break;
                        if(n[i].zl<=w){
                                w-=n[i].zl;
                                ans+=n[i].zj;
                        }
                        else{
                                ans+=n[i].dj*w;
                                break;
                        }
                }
                printf("%.2lf\n",ans);
        }
        return 0;
}
