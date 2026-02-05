#include <cstdio>
int main(){
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
        int n,a[110],max=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
                max=a[i]>max ? a[i] : max;
        }
        int min=max;
        for(int i=0;i<n;i++) min=a[i]<min ? a[i] : min;
        printf("%d",max-min);
        return 0;
}
