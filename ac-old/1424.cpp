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
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
                scanf("%d",&t[i].data);
                t[i].xb=i;
        }
        sort(t,t+n,cmp);
        for(int i=0;i<n;i++) printf("%d ",t[i].xb+1);
        long long sum=0;
        for(int i=0;i<m;i++) for(int j=i;j<n;j+=m) sum+=t[j].data*((n-1-j)/m);
        printf("\n%.2lf",double(sum)/n);
        return 0;
}
