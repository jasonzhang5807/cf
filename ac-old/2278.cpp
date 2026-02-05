#include <cstdio>
struct Node{
        int deep,data,lchild,rchild;
} p[110];
void preorder(int d,Node n){
        p[n.data].deep=d+1;
        if(n.lchild!=0) preorder(d+1,p[n.lchild]);
        if(n.rchild!=0) preorder(d+1,p[n.rchild]);
}
int main(){
        int n,r;
        scanf("%d %d",&n,&r);
        for(int i=1;i<=n;i++){
                scanf("%d %d",&p[i].lchild,&p[i].rchild);
                p[i].data=i;
        }
        preorder(0,p[r]);
        for(int i=1;i<=n;i++) printf("%d\n",p[i].deep);
        return 0;
}
