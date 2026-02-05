#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
const int MAXN=2000000;
int n,k,val[MAXN<<2],lazy[MAXN<<2];
priority_queue<int> small;
priority_queue<int,vector<int>,greater<int> > large;
void zws_add(int ipt){
        if(large.empty()) large.push(ipt);
        else{
                if(ipt>=large.top()){
                        large.push(ipt);
                        if(large.size()>small.size()) small.push(large.top()),large.pop();
                }
                else{
                        small.push(ipt);
                        if(large.size()<small.size()) large.push(small.top()),small.pop();
                }
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
void update(int rt,int l,int r,int ul,int ur){
        if(ul>r||ur<l) return;
        if(ul<=l&&ur>=r){
                val[rt]++;
                lazy[rt]++;
                return;
        }
        push_down(rt);
        int mid=(l+r)/2;
        update(rt*2,l,mid,ul,ur);
        update(rt*2+1,mid+1,r,ul,ur);
}
void bl(int rt,int l,int r){
    push_down(rt);
        if(l==r){
                zws_add(val[rt]);
                return;
        }
        int mid=(l+r)/2;
        bl(rt*2,l,mid);
        bl(rt*2+1,mid+1,r);
}
int main(){
    freopen("brick.in","r",stdin);
        freopen("brick.out","w",stdout);
        int a,b;
        scanf("%d%d",&n,&k);
        while(k--){
                scanf("%d%d",&a,&b);
                update(1,1,n,a,b);
        }
        bl(1,1,n);
        printf("%d",large.top());
        return 0;
}
