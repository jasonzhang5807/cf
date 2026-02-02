#include <bits/stdc++.h>
#define maxn 6000010
class arr{
    public:
        int val[maxn],rbp,lch[maxn],rch[maxn],rt[800010],currver;
        void build(int rt,int l,int r){
            if(l==r)return;
            int mid=l+r>>1;
            lch[rt]=++rbp;
            rch[rt]=++rbp;
            build(lch[rt],l,mid);
            build(rch[rt],mid+1,r);
        }
        int query(int rt,int l,int r,int pos){
            if(l==r)return val[rt];
            int mid=l+r>>1;
            if(pos<=mid){
                assert(lch[rt]);
                return query(lch[rt],l,mid,pos);
            }
            else{
                assert(rch[rt]);
                return query(rch[rt],mid+1,r,pos);
            }
        }
        inline int operator[](int x){
            return query(rt[currver],1,200005,x);
        }
        void update(int rt1,int rt2,int l,int r,int pos,int x){
            if(l==r){
                val[rt1]=x;
                return;
            }
            int mid=l+r>>1;
            if(pos<=mid){
                rch[rt1]=rch[rt2];
                lch[rt1]=++rbp;
                update(lch[rt1],lch[rt2],l,mid,pos,x);
            }
            else{
                lch[rt1]=lch[rt2];
                rch[rt1]=++rbp;
                update(rch[rt1],rch[rt2],mid+1,r,pos,x);
            }
        }
        inline void equ(int pos,int x){
            ++currver;
            update(rt[currver],rt[currver-1],1,200005,pos,x);
        }
};
