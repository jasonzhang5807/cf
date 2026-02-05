#include <cstdio>
#include <cstring>
char map[110][110];
int dat[110][110];
int ans=0x3f3f3f3f;
int miin(int x,int y,int a,int b,int c,int d){
        if(map[x-1][y]=='#')a=0x3f3f3f3f;
        if(map[x][y-1]=='#')b=0x3f3f3f3f;
        if(map[x+1][y]=='#')c=0x3f3f3f3f;
        if(map[x][y+1]=='#')d=0x3f3f3f3f;
        if(a==b&&b==c&&c==d&&a==0x3f3f3f3f) return 0x3f3f3f3f;
        int t=a<b?a:b;
        int t2=c<d?c:d;
        t=t<t2?t:t2;
        return (t+1)<dat[x][y]?(t+1):dat[x][y];
}
int main(){
        int n,m,dx,dy,x,y;
        scanf("%d%d",&n,&m);
        memset(map,'.',sizeof(map));
        memset(dat,0x3f,sizeof(dat));
        for(int i=1;i<=n;i++)scanf("%s",map[i]+1);
        bool flag1=true;
        for(int i=1;i<=n&&flag1;i++)
                for(int j=1;j<=m&&flag1;j++)
                        if(map[i][j]=='S')x=i,y=j,dat[i][j]=0,flag1=false;
        flag1=true;
        bool flag=false;
        for(int i=1;i<=n&&flag1;i++)
                for(int j=1;j<=m&&flag1;j++)
                        if(map[i][j]=='E')dx=i,dy=j,flag1=false;
        flag1=true;
        for(int i=1;i<=n&&flag1;i++)
                for(int j=1;j<=m&&flag1;j++)
                        if(map[i][j]=='#')flag=true,flag1=false;
        if(!flag){
                printf("%d",(x-dx)*((x-dx>0)?1:-1)+(y-dy)*((y-dy>0)?1:-1));
                return 0;
        }
        int cnt=0;
        while(1){
                for(int i=1;i<=n;i++)
                        for(int j=1;j<=m;j++)
                                dat[i][j]=miin(i,j,dat[i-1][j],dat[i][j-1],dat[i+1][j],dat[i][j+1]);
                if(dat[dx][dy]!=0x3f3f3f3f){
                        printf("%d",dat[dx][dy]);
                        return 0;
                }
                cnt++;
                if(cnt>=10086){
                        printf("-1");
                        return 0;
                }
        }
        return 0;
}
