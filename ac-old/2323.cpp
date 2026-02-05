#include <bits/stdc++.h>
using namespace std;
int d[1000010],n=0,k,add;
char ipt;
void up(int x){
        while(x>1){
                int i=x/2;
                if(d[x]<d[i]) swap(d[x],d[i]),x=i;
                else break;
        }
}
void down(int x){
        while(x*2<=n){
                int i=2*x;
                if(i+1<=n&&d[i+1]<d[i]&&d[x]>d[i+1]) swap(d[x],d[i+1]),x=i+1;
                else if(d[x]>d[i]) swap(d[x],d[i]),x=i;
                else break;
        }
}
void del_t(int pos){
        swap(d[pos],d[n]);
        n--;
        //up(pos) is disabled if pos is the root.
        down(pos);
}
int main(){
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
                scanf("%c",&ipt);
                if(ipt=='a'){
                        scanf("%d",&add);
                        n++;
                        d[n]=add;
                        up(n);
                }
                else if(ipt=='q'){
                        printf("%d\n",d[1]);
                        del_t(1);
                }
                else i--;
        }
        return 0;
}
