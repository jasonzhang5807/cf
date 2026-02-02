//zhangxinyu 11/13/2025 finished in 8'45"
#include <bits/stdc++.h>
using namespace std;
int val[800010],tag[800010],init_val[200010];
inline void pushup(int rt){
    val[rt]=val[rt<<1]+val[rt<<1|1];
}
inline void pushdown(int rt,int l,int r){
    if(tag[rt]){
        tag[rt<<1]+=tag[rt];
        tag[rt<<1|1]+=tag[rt];
        int mid=(l+r>>1);
        val[rt<<1]+=tag[rt]*(mid-l+1);
        val[rt<<1|1]+=tag[rt]*(r-mid);
        tag[rt]=0;
    }
}
void build(int rt,int l,int r){
    if(l==r){
        val[rt]=init_val[l];
        return;
    }
    int mid=(l+r>>1);
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r,int ul,int ur,int add){
    if(ul>r||ur<l)return;
    if(l==r){
        val[rt]+=add;
        return;
    }
    if(ul<=l&&ur>=r){
        tag[rt]+=add;
        val[rt]+=add*(r-l+1);
        return;
    }
    int mid=(l+r>>1);
    pushdown(rt,l,r);
    update(rt<<1,l,mid,ul,ur,add);
    update(rt<<1|1,mid+1,r,ul,ur,add);
    pushup(rt);
}
int query(int rt,int l,int r,int ql,int qr){
    if(ql>r||qr<l)return 0;
    if(ql<=l&&qr>=r)return val[rt];
    int mid=(l+r>>1);
    pushdown(rt,l,r);
    return query(rt<<1,l,mid,ql,qr)+query(rt<<1|1,mid+1,r,ql,qr);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>init_val[i];
    }
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>a>>b>>c;
            update(1,1,n,a,b,c);
        }
        else{
            cin>>b>>c;
            cout<<query(1,1,n,b,c)<<'\n';
        }
    }
    return 0;
}
