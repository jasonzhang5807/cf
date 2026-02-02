#include <cstdio>
#include <algorithm>
#include <cstring>
int tree[105][105],s[105][2],opt[105][105],n,mq;
void findc(int crt){
        bool flag=false;
        for(int i=1;i<=n;i++){
                if(tree[crt][i]!=-1){
                        flag=true;
                        if(s[crt][0]==0) s[crt][0]=i;
                        else s[crt][1]=i;
                        tree[i][crt]=-1;
                }
        }
        if(flag){
                findc(s[crt][0]);
                findc(s[crt][1]);
        }
}
void dp(int rt,int q){
        int t=std::max(opt[s[rt][1]][q-1]+std::max(0,tree[rt][s[rt][1]]),opt[s[rt][0]][q-1]+std::max(0,tree[rt][s[rt][0]]));
        for(int k=0;k<=q-2;k++) t=std::max(t,opt[s[rt][0]][k]+opt[s[rt][1]][q-2-k]+std::max(0,tree[rt][s[rt][0]])+std::max(0,tree[rt][s[rt][1]]));
        opt[rt][q]=t;
}
void porder(int rt){
        if(s[rt][0]==0&&s[rt][1]==0) return;
        porder(s[rt][0]);
        porder(s[rt][1]);
        for(int i=1;i<=mq;i++) dp(rt,i);
}
int main(){
        memset(tree,0xff,sizeof(tree));
        scanf("%d%d",&n,&mq);
        for(int i=0;i<n-1;i++){
                int i1,i2,i3;
                scanf("%d%d%d",&i1,&i2,&i3);
                tree[i1][i2]=i3;
                tree[i2][i1]=i3;
        }
        findc(1);
        porder(1);
        //for(int i=0;i<=n;i++){
        //        for(int j=0;j<=n;j++){
        //                printf("%d\t",opt[i][j]);
        //        }
        //        putchar('\n');
        //}
        //for(int i=0;i<=n;i++)printf("{%d,%d}\n",s[i][0],s[i][1]);
        //for(int i=0;i<=n;i++){
        //      for(int j=0;j<=n;j++){
        //              printf("%d\t",tree[i][j]);
        //      }
        //      putchar('\n');
        //}
        printf("%d",opt[1][mq]);
        return 0;
}
