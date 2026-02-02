#include <bits/stdc++.h>
using namespace std;
struct matrix{
    int r,c;
    long double val[110][210];
    inline long double* operator[](int x){
        return val[x];
    }
    void swpr(int a,int b){
        for(int i=1;i<=c;++i)
            swap(val[a][i],val[b][i]);
    }
    void div(int a,long double x){
        for(int i=1;i<=c;++i)
            val[a][i]=val[a][i]/x;
    }
    void subr(int a,int b,long double x){
        for(int i=1;i<=c;++i)val[a][i]-=val[b][i]*x;
    }
} a;
inline void ns(){
    cout<<"No Solution";
    exit(0);
}
double b[110];
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin>>n;
    a.r=n;a.c=n<<1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
        cin>>b[i];
    }
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
        double ans=0;
        for(int j=1;j<=n;++j)ans+=a[i][j+n]*b[j];
        printf("%.2lf\n",ans);
    }
    return 0;
}
