#include <cstdio>
#include <algorithm>
int main(){
        int t,n,r;
        scanf("%d",&t);
        while(t--){
                scanf("%d%d",&n,&r);
                if(n%10==0){
                        printf("1\n");
                        continue;
                }
                int ans=10;
                if(n%2==0)ans=5;
                if(n%5==0)ans=2;
                int ans2=0;
                bool flag=false;
                while(ans2<ans){
                        if(r==0){
                                printf("%d\n",ans2);
                                flag=true;
                                break;
                        }
                        r-=n;
                        //while(r<0)r+=10;
                        r%=10;
                        if(r<0)r+=10;
                        //printf("%d\n",r);
                        ans2++;
                }
                if(!flag)printf("%d\n",ans);
        }
        return 0;
}
