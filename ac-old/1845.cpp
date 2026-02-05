#include <queue>
#include <cstdio>
#define maxn 100010
using namespace std;
int main(){
	priority_queue<int> pq;
	int n,m;
	scanf("%d",&n);
	while(n--){		
		scanf("%d",&m);
		pq.push(m);
	}
	while(!pq.empty()){
		printf("%d\n",pq.top());
		pq.pop();
	}
	return 0;
}
