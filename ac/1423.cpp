#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
        int data,xb;
}t[1010];
bool cmp(Node x,Node y){
        if(x.data!=y.data) return x.data<y.data;
        else return x.xb<y.xb;
}
int main(){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&t[i].data);
                t[i].xb=i;
        }
        sort(t,t+n,cmp);
        for(int i=0;i<n;i++) printf("%d ",t[i].xb+1);
        long long sum=0;
        for(int i=0;i<n;i++) sum+=t[i].data*(n-i-1);
        double ans=double(sum)/n;
        printf("\n%.2lf",ans);
        return 0;
}
