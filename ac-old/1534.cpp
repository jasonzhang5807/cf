#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int order[1010];
void fuck(){
    printf("Impossible");
    exit(0);
}
int main(){
    int n;
    cin>>n;
    stack<int> c;
    for(int i=1;i<=n;i++)scanf("%d",&order[i]);
    int pos=1;
    for(int i=1;i<=n;){
        if(i>n)fuck();
        if(i==order[pos])pos++,i++;
        else if(!c.empty()&&c.top()==order[pos])pos++,c.pop();
        else c.push(i),i++;
    }
    while(!c.empty()){
        if(c.top()==order[pos])c.pop(),pos++;
        else fuck();
    }
    printf("Possible");
    return 0;
}
