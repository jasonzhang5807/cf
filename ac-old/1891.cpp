#include <cstdio>
int pk(int x,int y){
        if(x==0&&y==1) return 2;
        if(x==0&&y==2) return 1;
        if(x==0&&y==3) return 1;
        if(x==0&&y==4) return 2;
        if(x==1&&y==0) return 1;
        if(x==1&&y==2) return 2;
        if(x==1&&y==3) return 1;
        if(x==1&&y==4) return 2;
        if(x==2&&y==0) return 2;
        if(x==2&&y==1) return 1;
        if(x==2&&y==3) return 2;
        if(x==2&&y==4) return 1;
        if(x==3&&y==0) return 2;
        if(x==3&&y==1) return 2;
        if(x==3&&y==2) return 1;
        if(x==3&&y==4) return 1;
        if(x==4&&y==0) return 1;
        if(x==4&&y==1) return 1;
        if(x==4&&y==2) return 2;
        if(x==4&&y==3) return 2;
        return 0;
}
int main(){
        int n,na,nb,aa=0,bb=0;
        scanf("%d %d %d",&n,&na,&nb);
        int a[na],b[nb];
        for(int i=0;i<na;i++) scanf("%d",&a[i]);
        for(int i=0;i<nb;i++) scanf("%d",&b[i]);
        for(int i=0;i<n;i++){
                int result=pk(a[i%na],b[i%nb]);
                if(result==1) aa++;
                if(result==2) bb++;
        }
        printf("%d %d",aa,bb);
        return 0;
}
