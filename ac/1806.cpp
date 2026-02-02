#include <cstdio>
int main(){
        int n,d,p[2010],ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                bool flag=false;
                scanf("%d",&d);
                for(int j=0;j<ans;j++){
                        if(p[j]>=d){
                                p[j]=d;
                                flag=true;
                                break;
                        }
                }
                if(flag==false){
                        p[ans]=d;
                        ans++;
                }
        }
        printf("%d",ans);
        return 0;
}
