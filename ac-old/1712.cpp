#include <cstdio>
void prt_int128(__int128 prt){
        if(prt<0){
                putchar('-');
                prt_int128(-prt);
                return;
        }
        if(prt>9) prt_int128(prt/10);
        putchar(prt%10+'0');
}
__int128 s[55][55];
int main(){
        int n,m,t;
        scanf("%d%d%d",&n,&m,&t);
        if(t==0){
                s[0][0]=1;
                for(int i=0;i<m;i++){
                        for(int j=0;j<n;j++){
                                if(i==0&&j==0) continue;
                                if(i==0) s[0][j]=s[0][j-1];
                                else if(j==0) s[i][0]=s[i-1][0];
                                else s[i][j]=s[i-1][j]+s[i][j-1];
                        }
                }
                prt_int128(s[m-1][n-1]);
        }
        else{
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                s[0][0]=1;
                for(int i=x1-1;i<x2;i++) for(int j=y1-1;j<y2;j++) s[i][j]=-1;
                for(int i=0;i<m;i++){
                        for(int j=0;j<n;j++){
                                if(i==0&&j==0||s[i][j]==-1) continue;
                                if(i==0) s[0][j]=(s[0][j-1]==-1 ? 0 : s[0][j-1]);
                                else if(j==0) s[i][0]=(s[i-1][0]==-1 ? 0 : s[i-1][0]);
                                else s[i][j]=(s[i-1][j]==-1 ? 0 : s[i-1][j])+(s[i][j-1]==-1 ? 0 : s[i][j-1]);
                        }
                }
                prt_int128(s[m-1][n-1]==-1 ? 0 : s[m-1][n-1]);
        }
        return 0;
}
