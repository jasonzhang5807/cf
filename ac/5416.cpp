#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int main(){
    int n;
    vector<int> dp;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        auto tmp2=upper_bound(dp.begin(),dp.end(),tmp);
        if(tmp2==dp.end())dp.push_back(tmp);
        else *tmp2=tmp;
    }
    cout<<dp.size();
    return 0;
}
