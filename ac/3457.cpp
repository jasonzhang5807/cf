#include <bits/stdc++.h>
using namespace std;
int b;
struct req{
        int l,r,num;
        inline bool operator<(const req &nxt){return (l/b==nxt.l/b)?(r<nxt.r):(l/b<nxt.l/b);}
} q[50010];
int n,m,a[50010],md[50010],ans[50010],l=2,r=1;
int main(){
        cin>>n>>m;
        b=sqrt(n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=0;i<m;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].num=i;
        sort(q,q+m);
        for(int i=0;i<m;++i){
                if(i)ans[q[i].num]=ans[q[i-1].num];
                while(r<q[i].r)if(++md[a[++r]]==3)++ans[q[i].num];
                while(l>q[i].l)if(++md[a[--l]]==3)++ans[q[i].num];
                while(r>q[i].r)if(--md[a[r--]]==2)--ans[q[i].num];
                while(l<q[i].l)if(--md[a[l++]]==2)--ans[q[i].num];
        }
        for(int i=0;i<m;++i)printf("%d\n",ans[i]);
        return 0;
}
