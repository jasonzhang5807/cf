#include <bits/stdc++.h>
using namespace std;
int val[230][250],tag[250],n,b;
int main(){
        cin>>n;
        b=sqrt(n);
        int t;
        for(int i=1;i<=n;++i)scanf("%d",&val[(i-1)/b][(i-1)%b+1]);
        while(n--){
                int op,l,r,c;
                scanf("%d%d%d%d",&op,&l,&r,&c);
                if(op)printf("%d\n",val[(r-1)/b][(r-1)%b+1]+tag[(r-1)/b]);
                else{
                        if((l-1)/b==(r-1)/b)for(int i=(l-1)%b+1;i<=(r-1)%b+1;++i)val[(l-1)/b][i]+=c;
                        else{
                                for(int i=(l-1)%b+1;i<=b;++i)val[(l-1)/b][i]+=c;
                                for(int i=1;i<=(r-1)%b+1;++i)val[(r-1)/b][i]+=c;
                                for(int i=(l-1)/b+1;i<=(r-1)/b-1;++i)tag[i]+=c;
                        }
                }
        }
        return 0;
}
