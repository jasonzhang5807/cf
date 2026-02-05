#include <cstdio>
int value[100];
struct Node{
        int poi,data,lchild,rchild;
} p[110];
void preorder(Node n){
        value[n.poi]+=n.data;
        value[p[n.lchild].poi]+=value[n.poi];
        value[p[n.rchild].poi]+=value[n.poi];
        if(n.lchild!=0) preorder(p[n.lchild]);
        if(n.rchild!=0) preorder(p[n.rchild]);
}
int main(){
        int n,r;
        scanf("%d %d",&n,&r);
        for(int i=1;i<=n;i++){
                scanf("%d %d %d",&p[i].data,&p[i].lchild,&p[i].rchild);
                p[i].poi=i;
        }
        preorder(p[r]);
        for(int i=1;i<=n;i++) printf("%d\n",value[i]);
        return 0;
}
