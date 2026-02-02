#include <cstdio>
struct Node{
        int data,lchild,rchild;
} p[110];
void preorder(Node n){
        printf("%d ",n.data);
        if(n.lchild!=0) preorder(p[n.lchild]);
        if(n.rchild!=0) preorder(p[n.rchild]);
}
void inorder(Node n){
        if(n.lchild!=0) inorder(p[n.lchild]);
        printf("%d ",n.data);
        if(n.rchild!=0) inorder(p[n.rchild]);
}
void rorder(Node n){
        if(n.lchild!=0) rorder(p[n.lchild]);
        if(n.rchild!=0) rorder(p[n.rchild]);
        printf("%d ",n.data);
}
int main(){
        int n,r;
        scanf("%d %d",&n,&r);
        for(int i=1;i<=n;i++){
                scanf("%d %d",&p[i].lchild,&p[i].rchild);
                p[i].data=i;
        }
        preorder(p[r]);
        printf("\n");
        inorder(p[r]);
        printf("\n");
        rorder(p[r]);
        return 0;
}
