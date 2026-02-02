#include <cstdio>
#include <algorithm>
int cnt[610];
using namespace std;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
        int n,w,p;
        scanf("%d %d",&n,&w);
        int a[n+10];
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
                cnt[a[i]]++;
                p=max(1,i*w/100);
                for(int j=600;j>=0;j--){
                        if(p<=cnt[j]){
                                printf("%d ",j);
                                break;
                        }
                        else p-=cnt[j];
                }
        }
        return 0;
}
