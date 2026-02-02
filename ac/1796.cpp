#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int rbp;
bool o[maxn];
int e[maxn][10];
string buf;
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
                rbp=2;
                memset(o,0,sizeof(o));
                o[1]=1;
                memset(e,0,sizeof(e));
                int n,poi=1;
                cin>>n;
                bool f=0;
                while(n--){
                        cin>>buf;
                        bool flag=0;
                        poi=1;
                        for(char x:buf){
                                if(!e[poi][x-'0'])flag=1,e[poi][x-'0']=rbp++;
                                poi=e[poi][x-'0'];
                                if(o[poi])f=1;
                        }
                        o[poi]=1;
                        if(!flag)f=1;
                }
                cout<<(f?"NO":"YES")<<'\n';
        }
        return 0;
}
