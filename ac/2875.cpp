#include <bits/stdc++.h>
#define maxn 50010
using namespace std;
int b,buf[maxn],cnt[1000010],ans[200010],cur;
struct req{
	int l,r,num;
	inline bool operator<(const req &nxt)const{
		return l/b!=nxt.l/b?l/b<nxt.l/b:r<nxt.r;
	}
};
req q[200010];
int main(){
	int n;
	cin>>n;
	b=sqrt(n);
	for(int i=1;i<=n;++i)scanf("%d",&buf[i]);
	int m;
	cin>>m;
	for(int i=0;i<m;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].num=i;
	sort(q,q+m);
	int l=1,r=0;
	for(int i=0;i<m;++i){
		while(l<q[i].l){
			cnt[buf[l]]--;
			if(cnt[buf[l]]==0)cur--;
			l++;
		}
		while(l>q[i].l){
			l--;
			cnt[buf[l]]++;
			if(cnt[buf[l]]==1)cur++;
		}
		while(r<q[i].r){
			r++;
			cnt[buf[r]]++;
			if(cnt[buf[r]]==1)cur++;
		}
		while(r>q[i].r){
			cnt[buf[r]]--;
			if(cnt[buf[r]]==0)cur--;
			r--;
		}
		ans[q[i].num]=cur;
	}
	for(int i=0;i<m;++i)printf("%d\n",ans[i]);
	return 0;
}
