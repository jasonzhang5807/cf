#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main(){
        priority_queue<long long,vector<long long>,greater<long long>> q;
        q.push(1);
        long long n,ipt,rec=1;
        scanf("%lld",&n);
        for(int i=0;i<n;i++){
                q.push(2*q.top());
                q.push(3*q.top());
                q.push(5*q.top());
                q.push(7*q.top());
                rec=q.top();
                while(q.top()==rec) q.pop();
        }
        printf("%lld",rec);
        return 0;
}
