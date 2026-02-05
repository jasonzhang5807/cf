#include <bits/stdc++.h>
using namespace std;
int f[1010],p[1010],s,t,n;
int main(){
        cin>>n>>s>>t;
        memset(f,0xc1,sizeof(f));
        for(int i=1;i<=n;++i)scanf("%d",&p[i]);
        f[1]=p[1];
        for(int i=2;i<=n;++i){
                int add=0xc1c1c1c1;
                bool flag=false;
                for(int j=s;j<=t;++j){
                        if(i<=j)break;
                        flag=true;
                        add=max(f[i-j],add);
                }
                if(flag)f[i]=p[i]+add;
                //printf("i=%d\n",i);
                //for(int i=1;i<=n;++i)printf("%d ",f[i]);
                //printf("\n");
        }
        cout<<((f[n]<0)?-1:f[n]);
        return 0;
}
