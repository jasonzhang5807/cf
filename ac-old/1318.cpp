#include <bits/stdc++.h>
using namespace std;
bool cmp(string a){
    auto l=a.begin();
    auto r=a.end()-1;
    while(l<r){
        if(*l!=*r)return false;
        ++l;--r;
    }
    return true;
}
int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.size();++i){
        if(cmp(a)){
            cout<<i<<endl<<a;
            return 0;
        }
        a=a+*a.begin();
        a.erase(0,1);
    }
    printf("-1");
    return 0;
}
