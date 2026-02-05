#include <cstdio>
#include <algorithm>
using namespace std;
int n,q,d[1010],t,len,p[10];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    for(int i=0,j=1;i<10;i++,j*=10) p[i]=j;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    sort(d+1,d+(n+1));
    for (int i=1;i<=q;i++) {
        scanf("%d %d",&len,&t);
        int ans=-1;
        for (int j=1;j<=n;j++) {
            if (d[j]<t) continue;
            if (d[j]%p[len]==t) {
                ans=d[j];
		break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
