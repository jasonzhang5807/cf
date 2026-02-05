#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,s1,s2;
    cin>>s>>s1>>s2;
    int l=s.find(s1);
    int r=s.rfind(s2);
    if(l==string::npos||r==string::npos)printf("-1");
    else if(l+s1.size()>r)printf("-1");
    else printf("%ld",r-l-s1.size());
    return 0;
}
