#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
queue<int> pd;
int xm[400000],poi;
int main(){
        int n,k,p;
        bool flag=false;
        scanf("%d%d%d",&n,&k,&p);
        for(int i=1;i<=k;i++)pd.push(i);
        while(!pd.empty()){
                for(int j=1;j<n;j++){
                        if(pd.empty()){
                                flag=true;
                                break;
                        }
                        pd.pop();
                        for(int l=0;l<p;l++)pd.push(pd.front()),pd.pop();
                }
                if(pd.empty())break;
                xm[poi]=pd.front();
                pd.pop();
                poi++;
                if(pd.empty())break;
                for(int l=0;l<p;l++)pd.push(pd.front()),pd.pop();
        }
        sort(xm,xm+poi);
        for(int i=0;i<poi;i++)printf("%d\n",xm[i]);
        return 0;
}
