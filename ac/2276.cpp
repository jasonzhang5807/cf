#include <cstdio>
struct Node{
        int poi,data,lchild,rchild;
} p[110];
int sum(Node n){
        if(n.lchild==0&&n.rchild==0) return n.data;
        if(n.lchild!=0&&n.rchild==0) return n.data+sum(p[n.lchild]);
        if(n.rchild!=0&&n.lchild==0) return n.data+sum(p[n.rchild]);
        if(n.rchild!=0&&n.rchild!=0) return n.data+sum(p[n.lchild])+sum(p[n.rchild]);
}
int main(){
        int n,r;
        scanf("%d %d",&n,&r);
        for(int i=1;i<=n;i++){
                scanf("%d %d %d",&p[i].data,&p[i].lchild,&p[i].rchild);
                p[i].poi=i;
        }
        for(int i=1;i<=n;i++) printf("%d\n",sum(p[i]));
        return 0;
}
