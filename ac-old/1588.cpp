#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long trans(long long a,long long n){
    long long res=0;
    long long len=to_string(a).length();
    len=0;
    while(a>0){
        long long x=a%10;
        res+=x*pow(n,len++);
        a/=10;
    }
    return res;
}
int main(){
    long long p,q,r;
    cin>>p>>q>>r;
    string str=to_string(p)+to_string(q)+to_string(r);
    char max='0';
    for(long long i=0;i<str.length();i++){
        if(str[i]>max) max=str[i];
    }
    long long maxn=(long long)max-48;
    for(long long i=maxn+1;i<=17;i++){
        if(trans(p,i)*trans(q,i)==trans(r,i)){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
