#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main(){
        string s;
        stack<int> lft;
        cin>>s;
        for(int i=0;i<s.size();i++){
                if(s[i]=='(')lft.push(i);
                else{
                        printf("%d %d\n",lft.top(),i);
                        lft.pop();
                }
        }
        return 0;
}
