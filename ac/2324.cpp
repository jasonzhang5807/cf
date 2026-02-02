#include <bits/stdc++.h>
using namespace std;
struct Node{
        int num,val;
} d[1000010];
Node add;
int n=0,k;
char ipt;
void up(int x){
        while(x>1){
                int i=x/2;
                if(d[x].num<d[i].num||d[x].num==d[i].num&&d[x].val>d[i].val) swap(d[x],d[i]),x=i;
                else break;
        }
}
void down(int x){
        while(x*2<=n){
                int i=2*x;
                if(i+1<=n&&(d[i+1].num<d[i].num||d[i+1].num==d[i].num&&d[i+1].val>d[i].val)&&(d[x].num>d[i+1].num||d[x].num==d[i+1].num&&d[x].val<d[i+1].val)) swap(d[x],d[i+1]),x=i+1;
                else if(d[x].num>d[i].num||d[x].num==d[i].num&&d[x].val<d[i].val) swap(d[x],d[i]),x=i;
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
                        scanf("%d%d",&add.num,&add.val);
                        n++;
                        d[n].num=add.num;
                        d[n].val=add.val;
                        up(n);
                }
                else if(ipt=='q'){                                                                                                                                          
                        printf("%d %d\n",d[1].num,d[1].val);
                        del_t(1);
                }
                else i--;
        }
        return 0;
}
