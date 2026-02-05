#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){return a.second<b.second;}
int main(){
	int n;
	pair<int,int> a[1010];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i].first=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)printf("%d ",a[i].first);
	return 0;
}
