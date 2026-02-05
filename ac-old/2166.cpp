#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int inv(int x){
    if(x<=1)return 1;
    return int(1LL*(mod-mod/x)*inv(mod%x)%mod);
}
struct matrix{
    int r,c,val[410][810];
    inline int* operator[](int x){
        return val[x];
    }
    void swpr(int a,int b){
        for(int i=1;i<=c;++i)
            swap(val[a][i],val[b][i]);
    }
    void div(int a,int x){
        int ix=inv(x);
        for(int i=1;i<=c;++i)
            val[a][i]=int(1LL*val[a][i]*ix%mod);
    }
    void subr(int a,int b,int x){
        for(int i=1;i<=c;++i){
            val[a][i]=int((val[a][i]-1LL*val[b][i]*x%mod+mod)%mod);
        }
    }
} a;
inline void ns(){
    cout<<"No Solution";
    exit(0);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    a.r=n;a.c=n<<1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    for(int i=1,j=i+n;i<=n;++i,++j)
        a[i][j]=1;
    for(int i=1;i<=n;++i){
        if(!a[i][i]){
            bool flag=0;
            for(int j=i+1;j<=n;++j)
                if(a[j][i]){
                    a.swpr(i,j);flag=1;
                    break;
                }
            if(!flag)ns();
        }
        a.div(i,a[i][i]);
        for(int j=i+1;j<=n;++j)
            if(a[j][i])a.subr(j,i,a[j][i]);
    }
    for(int i=n;i>=1;--i)
        for(int j=i-1;j>=1;--j)
            if(a[j][i])a.subr(j,i,a[j][i]);
    for(int i=1;i<=n;++i){
        for(int j=n+1;j<=n*2;++j){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
