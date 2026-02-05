#include <bits/stdc++.h>
using namespace std;
int b[8005];
struct node {
    int a;
    int w;
}a[8005];
int main() {
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i].a);
        a[i].w=i;
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j>=2;j--){
            if (a[j].a<a[j-1].a){
                swap(a[j],a[j-1]);
            }else{
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        b[a[i].w]=i;
    }
    for (int i=1;i<=q;i++){
        int t;
        scanf("%d",&t);
        if (t==1){
            int x,v;
            scanf("%d %d",&x,&v);
            int k=b[x];
            a[b[x]].a=v;
            for (int j=k;j<n;j++){
                if (a[j].a>a[j+1].a||a[j].a==a[j+1].a&&a[j].w>a[j+1].w){
                    swap(a[j],a[j+1]);
                    swap(b[a[j].w],b[a[j+1].w]);
                }else{
                    break;
                }
            }
            for (int j=k;j>=2;j--){
                if (a[j].a<a[j-1].a||a[j].a==a[j-1].a&&a[j].w<a[j-1].w){
                    swap(a[j],a[j-1]);
                    swap(b[a[j].w],b[a[j-1].w]);
                }else{
                    break;
                }
            }
        }else{
            int x;
            scanf("%d",&x);
            printf("%d\n",b[x]);
        }
    }
    return 0;
}
