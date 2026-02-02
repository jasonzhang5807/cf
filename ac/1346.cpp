#include <cstdio>
#include <algorithm>
const int MAXN=1000000;
int n,m,val[MAXN<<2],init_val[MAXN],lazy[MAXN<<2];
void push_up(int rt) {val[rt]=std::min(val[rt*2],val[rt*2+1]);}
void build(int rt,int l,int r){
        if(l==r) val[rt]=init_val[l];
        else{
                int mid=(l+r)/2;
                build(rt*2,l,mid);
                build(rt*2+1,mid+1,r);
                push_up(rt);
        }
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
void update(int rt,int l,int r,int ul,int ur,int add){
        if(ul>r||ur<l) return;
        if(ul<=l&&ur>=r){
                val[rt]+=add;
                lazy[rt]+=add;
                return;
        }
        push_down(rt);
        int mid=(l+r)/2;
        update(rt*2,l,mid,ul,ur,add);
        update(rt*2+1,mid+1,r,ul,ur,add);
        push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
        if(ql>r||qr<l) return 1e9;
        if(ql<=l&&qr>=r) return val[rt];
        push_down(rt);
        int mid=(l+r)/2;
        return std::min(query(rt*2,l,mid,ql,qr),query(rt*2+1,mid+1,r,ql,qr));
}
int main(){
    int k,p;
        scanf("%d%d%d",&n,&k,&p);
        k+=p;
        while(k--){
                int ipt;
                scanf("%d",&ipt);
                if(ipt==1){
                        int a,b;
                        scanf("%d%d",&a,&b);
                        update(1,1,n,a,b,1);
                }
                else{
                        int a,b;
                        scanf("%d%d",&a,&b);
                        printf("%d\n",query(1,1,n,a,b));
                }
        }
        return 0;
}
