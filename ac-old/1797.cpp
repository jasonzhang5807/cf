#include<bits/stdc++.h>
#define maxn 3200010
using namespace std;
int e[maxn][2],buf,rbp,n,ans;
vector<int> ipt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    rbp=2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>buf;
        ipt.push_back(buf);
        int poi=1;
        for(int bit=31;bit>=0;bit--){
            int t=(buf>>bit)&1;
            if(!e[poi][t])e[poi][t]=rbp++;
            poi=e[poi][t];
        }
    }
    for(int x:ipt){
        int poi=1,cur=0;
        for(int bit=31;bit>=0;bit--){
            int t=(x>>bit)&1;
            if(e[poi][t^1]){
                cur|=(1<<bit);
                poi=e[poi][t^1];
            }else{
                poi=e[poi][t];
            }
        }
        ans=max(ans,cur);
    }
    cout<<ans;
    return 0;
}
