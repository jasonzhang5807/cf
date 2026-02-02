#include <bits/stdc++.h>
using namespace std;
int b[511];
int main(){
    string s[511];
    int x=0;
    char tmp;
    while(1){
        ++x;
        if(!(cin>>s[x]))break;
        while(1){
            tmp=getchar();
            if(tmp!=' ')break;
            ++b[x];
        }
        cin.putback(tmp);
    }
    --x;
    for(int i=1;i<=x;++i){
        reverse(s[i].begin(),s[i].end());
        cout<<s[i];
        if(x!=i)while(b[i]--)putchar(' ');
    }
}
