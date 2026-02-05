#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 210
using namespace std;
int tot,sum[maxn<<2];
double len[maxn<<2],X[maxn<<2];
class L{
    public:
        double l,r,h;
        int mk;
        bool operator < (const L& nxt){
            return h<nxt.h;
        }
};
L line[maxn];
void pushup(int x,int l,int r){
    if(sum[x])len[x]=X[r+1]-X[l];
    else if(l==r)len[x]=0;
    else len[x]=len[x<<1]+len[x<<1|1];
}
void update(int x,int l,int r,double L,double R,int c){
    if(X[r+1]<=L||R<=X[l])return;
    if(L<=X[l]&&X[r+1]<=R){
        sum[x]+=c;
        pushup(x,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(x<<1,l,mid,L,R,c);
    update(x<<1|1,mid+1,r,L,R,c);
    pushup(x,l,r);
}
int main(){
	int cnt=0;
    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;
        ++cnt;
        memset(len,0,sizeof(len));
        memset(line,0,sizeof(line));
		memset(sum,0,sizeof(sum));
		memset(X,0,sizeof(X));
		tot=0; 
        for(int i=1;i<=n;i++){
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            X[2*i-1]=x1,X[2*i]=x2;
            line[2*i-1]=(L){x1,x2,y1,1};
            line[i<<1]=(L){x1,x2,y2,-1};
        }
        n<<=1;
        double ans=0;
        sort(line+1,line+n+1);
        sort(X+1,X+n+1);
        int tot=unique(X+1,X+n+1)-X-1;
        //puts("----------");
        //for(int i=1;i<n;i++)printf("%lf,%lf,%lf,%d\n",line[i].l,line[i].r,line[i].h,line[i].mk);
        //puts("============");
        for(int i=1;i<n;i++){
            update(1,1,tot-1,line[i].l,line[i].r,line[i].mk);
            ans+=len[1]*(line[i+1].h-line[i].h);
        }
        printf("Test case #%d\n%.2lf\n",cnt,ans);
    }
    return 0;
}
