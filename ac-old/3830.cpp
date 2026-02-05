#include <cstdio>
#include <cmath>
using namespace std;
int main(){
#ifndef test
        freopen("b.in","r",stdin);
        freopen("b.out","w",stdout);
#endif
        int n,xx[110],yy[110],hh[110],ansx,ansy,ansh,cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d%d%d",&xx[i],&yy[i],&hh[i]);
                if(hh[i]!=0){
                        cnt++;
                        ansx=xx[i];
                        ansy=yy[i];
                        ansh=hh[i];
                }
        }
        if(cnt==1){
                printf("%d %d %d",ansx,ansy,ansh);
                return 0;
        }
        for(int x=0;x<=100;x++){
                for(int y=0;y<=100;y++){
                        bool flag=true;
                        int h=-1;
                        for(int i=0;i<n;i++){
                                if(hh[i]==0) continue;
                                if(h==-1) h=hh[i]+abs(xx[i]-x)+abs(yy[i]-y);
                                if(h!=hh[i]+abs(xx[i]-x)+abs(yy[i]-y)){
                                        flag=false;
                                        break;
                                }
                        }
                        if(flag){
                                printf("%d %d %d",x,y,h);
                                return 0;
                        }
                }
        }
        return 0;
}
