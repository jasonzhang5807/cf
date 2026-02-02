#include <cstdio>
#include <queue>
using namespace std;
priority_queue<long long> abss;
int main(){
        int n;
        scanf("%d",&n);
        while(n--){
                long long t;
                scanf("%lld",&t);
                abss.push(-t);
        }
        long long cst=0;
        while(abss.size()>1){
                long long t=abss.top();
                abss.pop();
                t+=abss.top();
                abss.pop();
                cst-=t;
                abss.push(t);
        }
        printf("%lld",cst);
        return 0;
}
