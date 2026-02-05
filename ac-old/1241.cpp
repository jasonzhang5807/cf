#include <set>
#include <cstdio>
using namespace std;
int main(){
	set<int> s;
	int n,t;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		s.insert(t);
	}
	printf("%d\n",s.size());
	for(int x:s)printf("%d ",x);
	return 0;
}
