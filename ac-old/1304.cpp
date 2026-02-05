#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
        string a,b;
        cin>>a>>b;
        if(a.find(b)!=string::npos){printf("0");return 0;}
        a=a+a;
        if(a.find(b)==string::npos)printf("-1");
        else printf("%ld",+a.find(b)-a.size()/2+b.size());
        return 0;
}
