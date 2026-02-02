#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1,md;
void split(int x){
    if((x%2)^md||x<=m)return;
    ++ans;
    split(x+m>>1);
    split(x-m>>1);
}
int main(){
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
    cin>>n>>m;
    md=m%2;
    split(n);
    cout<<ans;
}
