#include <cstdio>
#include <stdlib.h>
#define maxn 100010
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
        split(root,v-1,x,y);
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
        int n,rt=0;
        scanf("%d",&n);
        while(n--){
                int opt,x;
                scanf("%d%d",&opt,&x);
                switch(opt){
                        case 1:
                                insert(rt,x);
                                break;
                        case 2:
                                del(rt,x);
                                break;
                        case 3:
                                printf("%d\n",query_rank(rt,x));
                                break;
                        case 4:
                                printf("%d\n",v[query_kth(rt,x)]);
                                break;
                        case 5:
                                printf("%d\n",v[pre(rt,x)]);
                                break;
                        case 6:
                                printf("%d\n",v[succ(rt,x)]);
                                break;
                        default:
                                printf("ERROR!\n");
                }
        }
        return 0;
}
