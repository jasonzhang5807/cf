#include <cstdio>
const int MAXN=100000;
int n,m,val[MAXN<<2],init_val[MAXN],lazy[MAXN<<2];
void push_up(int rt) {val[rt]=val[rt*2]+val[rt*2+1];}
void build(int rt,int l,int r){
        if(l==r) val[rt]=init_val[l];
        else{
                int mid=(l+r)/2;
                build(rt*2,l,mid);
                build(rt*2+1,mid+1,r);
                push_up(rt);
        }
}
void update_one(int rt,int l,int r,int idx,int add){
        if(l==r){
                val[rt]+=add;
                return;
        }
        int mid=(l+r)/2;
        if(idx<=mid) update_one(rt*2,l,mid,idx,add);
        else update_one(rt*2+1,mid+1,r,idx,add);
        push_up(rt);
}
void push_down(int rt){
        if(lazy[rt]!=0){
                lazy[rt*2]+=lazy[rt];
                lazy[rt*2+1]+=lazy[rt];
                val[rt*2]+=lazy[rt];
                val[rt*2+1]+=lazy[rt];
                lazy[rt]=0;
        }
}
int query(int rt,int l,int r,int ql,int qr){
        if(ql>r||qr<l) return 0;
        if(ql<=l&&qr>=r) return val[rt];
        push_down(rt);
        int mid=(l+r)/2;
        return query(rt*2,l,mid,ql,qr)+query(rt*2+1,mid+1,r,ql,qr);
}
int main(){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&init_val[i]);
        build(1,1,n);
        scanf("%d",&m);
        while(m--){
                int ipt,a,b;
                scanf("%d%d%d",&ipt,&a,&b);
                if(ipt==1) update_one(1,1,n,a,b);
                else printf("%d\n",query(1,1,n,a,b));
        }
        return 0;
}
