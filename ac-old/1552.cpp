#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
        int n,a[1010],cost=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=n;i>1;i--){
                sort(a,a+i);
                cost+=a[0]+a[1];
                a[0]+=a[1];
                for(int j=2;j<n;j++) a[j-1]=a[j];
        }
        printf("%d",cost);
        return 0;
}
