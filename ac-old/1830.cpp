#include <bits/stdc++.h>
#define maxn 30010
using namespace std;
int n,m;
int fa[maxn],dist[maxn],siz[maxn];
int find(int x) {
    if (fa[x] != x) {
        int root = find(fa[x]);
        dist[x] += dist[fa[x]];
        fa[x] = root;
    }
    return fa[x];
}
void merge(int x,int y){
    int ax = find(x);
    int ay = find(y);
    if (ax == ay) return;
    fa[ax] = ay;
    dist[ax] = dist[ay] + siz[ay];
    siz[ay] += siz[ax];
}
int main() {
    cin>>n>>m;
    for (int i = 1; i <= n; i++)fa[i]=i,siz[i]=1;
    while(m--) {
        getchar();
        char opt=getchar();
        if(opt=='M'){
            int a,b;
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else{
            int a;
            scanf("%d",&a);
            find(a);
            printf("%d\n",dist[a]);
        }
    }
    return 0;
}
