#include <cstdio>
#include <stdlib.h>
#include <stack>
#define maxn 100010
std::stack<int> dst;
int sz;
int ch[maxn][2],v[maxn],s[maxn],w[maxn];
int new_(int _v){
        ++sz;
        v[sz]=_v;w[sz]=rand();s[sz]=1;ch[sz][0]=ch[sz][1]=0;
        return sz;
}
inline void update(int rt){s[rt]=s[ch[rt][0]]+s[ch[rt][1]]+1;}
void split(int now,int k,int &x,int &y){
        if(!now)x=y=0;
        else{
                if(v[now]<=k)x=now,split(ch[now][1],k,ch[now][1],y);
                else y=now,split(ch[now][0],k,x,ch[now][0]);
                update(now);
        }
}
void split_kth(int now,int k,int &x,int &y){
        if(!now)x=y=0;
        else{
                if(k<=s[ch[now][0]])y=now,split_kth(ch[now][0],k,x,ch[now][0]);
                else x=now,split_kth(ch[now][1],k-s[ch[now][0]]-1,ch[now][1],y);
                update(now);
        }
}
int merge(int x,int y){
        if(!x||!y)return x+y;
        if(w[x]<w[y]){
                ch[x][1]=merge(ch[x][1],y);
                update(x);
                return x;
        }
        else{
                ch[y][0]=merge(x,ch[y][0]);
                update(y);
                return y;
        }
}
void insert(int &root,int v){
        int x,y;
        split(root,v,x,y);
        root=merge(merge(x,new_(v)),y);
}
int query_rank(int &root,int v){
        int x,y,ret;
        split(root,v-1,x,y);
        ret=s[x]+1;
        root=merge(x,y);
        return ret;
}
int pre(int &root,int v){
        int x,y,z;
        split(root,v,x,y);
        for(z=x;ch[z][1];z=ch[z][1]);
        root=merge(x,y);
        return z;
}
int succ(int &root,int v){
        int x,y,z;
        split(root,v,x,y);
        for(z=y;ch[z][0];z=ch[z][0]);
        root=merge(x,y);
        return z;
}
int query_kth(int &root,int k){
        int x,y,z;
        split_kth(root,k-1,x,y);
        split_kth(y,1,y,z);
        root=merge(merge(x,y),z);
        return y;
}
void del(int &root,int v){
        int x,y,z;
        split(root,v,x,z);
        split(x,v-1,x,y);
        y=merge(ch[y][0],ch[y][1]);
        root=merge(merge(x,y),z);
}
int main(){
        srand(1145141919);
        int n,m,x,rt=0;
        scanf("%d%d",&n,&m);
        insert(rt,0);
        insert(rt,n+1);
        while(m--){
                char opt;
                getchar();
                scanf("%c",&opt);
                switch(opt){
                        case 'D':
                                scanf("%d",&x);
                                insert(rt,x);
                                dst.push(x);
                                break;
                        case 'Q':
                                scanf("%d",&x);
                                if(v[pre(rt,x)]==x)printf("0\n");
                                else printf("%d\n",v[succ(rt,x)]-v[pre(rt,x)]-1);
                                break;
                        case 'R':
                                if(!dst.empty()){
                                        del(rt,dst.top());
                                        dst.pop();
                                }
                                break;
                        default:
                                printf("ERROR\n");
                                break;
                }
        }
        return 0;
}
