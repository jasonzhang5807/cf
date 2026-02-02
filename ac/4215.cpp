#include <bits/stdc++.h>
#define maxn 6800010
using namespace std;
int esp,lc[maxn],rc[maxn],v[maxn],tag[maxn];
inline void pushup(int rt){
        v[rt]=min(v[lc[rt]],v[rc[rt]]);
}
inline void pushdown(int rt){
        if(tag[rt]){
                if(!lc[rt])lc[rt]=++esp;
                if(!rc[rt])rc[rt]=++esp;
                tag[lc[rt]]+=tag[rt];
                tag[rc[rt]]+=tag[rt];
                v[lc[rt]]+=tag[rt];
                v[rc[rt]]+=tag[rt];
                tag[rt]=0;
        }
}
void update(int& rt,int l,int r,int ul,int ur,int add){
        if(ul>r||ur<l)return;
        if(!rt)rt=++esp;
        if(ul<=l&&ur>=r){
                v[rt]+=add;tag[rt]+=add;
                return;
        }
        pushdown(rt);
        int mid=l+r>>1;
        update(lc[rt],l,mid,ul,ur,add);
        update(rc[rt],mid+1,r,ul,ur,add);
        pushup(rt);
}
int query(int& rt,int l,int r,int ql,int qr){
        if(ql>r||qr<l)return 0x3f3f3f3f;
        if(!rt) return 0;
        if(ql<=l&&qr>=r)return v[rt];
        pushdown(rt);
        int mid=l+r>>1;
        return min(query(lc[rt],l,mid,ql,qr),query(rc[rt],mid+1,r,ql,qr));
}
int main(){
        int rt=1;
        esp=1;
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n,q,op,a,b,val;
        cin>>n>>q;
        while(q--){
                cin>>op;
                if(op&1){
                        cin>>a>>b>>val;
                        update(rt,1,n,a,b,val);
                }
                else{
                        cin>>a>>b;
                        cout<<query(rt,1,n,a,b)<<'\n';
                }
        }
        return 0;
}
