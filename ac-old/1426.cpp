#include <cstdio>
#include <algorithm>
using namespace std;
bool jq[1010];
struct yj{
        int x,y,t;
} s[510];
bool cmp(yj xx,yj yy){ return xx.y<yy.y;}
int main(){
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].t);
        sort(s,s+m,cmp);
        for(int i=0;i<m;i++){
                int a=0;
                for(int j=s[i].x;j<=s[i].y;j++) if(jq[j]==true) a++;
                for(int j=s[i].y;j>=s[i].x;j--){
                        if(s[i].t-a<=0) break;
                        if(jq[j]==false){
                                jq[j]=true;
                                a++;
                                ans++;
                        }
                }
        }
        printf("%d",ans);
        return 0;
}
