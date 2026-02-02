#include <bits/stdc++.h>
using namespace std;
int bit[32010],ans[50010];
pair<int,int> buf[50010];
void update(int x){
        while(x<32005){
                bit[x]++;
                x+=x&-x;
        }
}
int query(int x){
        int ret=0;
        while(x>0){
                ret+=bit[x];
                x-=x&-x;
        }
        return ret;
}
inline bool cmp(const pair<int,int> &a,const pair<int,int> &b){
        if(a.second!=b.second)return a.second<b.second;
        else return a.first<b.first;
}
int main(){
        int n;
        cin>>n;
        for(int i=0;i<n;++i)scanf("%d%d",&buf[i].first,&buf[i].second);
        sort(buf,buf+n,cmp);
        for(int i=0;i<n;++i){
                ++buf[i].first;
                update(buf[i].first);
                ++ans[query(buf[i].first)];
        }
        for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
        return 0;
}
