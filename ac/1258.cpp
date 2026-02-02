#include <bits/stdc++.h>
#define mod 10000
using namespace std;
vector<long long> a;
int main(){
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
        long long tmp=0,mul=-1;
        char ipt;
        while(1){
                tmp%=mod;
                mul%=mod;
                bool flag=1;
                ipt=getchar();
                if(ipt==EOF)break;
                if(ipt=='+'){
                        if(mul!=-1){
                                tmp*=mul;
                                mul=-1;
                                tmp%=mod;
                        }
                        a.push_back(tmp);
                        tmp=0;
                }
                else if(ipt=='*'){
                        if(mul==-1)mul=tmp,tmp=0;
                        else{
                                mul*=tmp;
                                tmp=0;
                                mul%=mod;
                        }
                }
                else if(ipt>='0'&&ipt<='9')tmp*=10,tmp+=ipt-'0',tmp%=mod;
                else break;
        }
        if(mul!=-1){
                        tmp*=mul;
                        mul=-1;
                        tmp%=mod;
                }
        a.push_back(tmp);
        long long ans=0;
        for(auto x:a){
                ans+=x;
                ans%=mod;
        }
        cout<<ans%10000;
        return 0;
}
