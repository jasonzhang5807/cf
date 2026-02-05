#include <cstdio>
int main(){
        int m,s,t,time=0,distance=0;
        scanf("%d%d%d",&m,&s,&t);
        while(1){
                if(s-distance<=0){
                        printf("Yes\n%d",time);
                        return 0;
                }
                if(t-time<=0){
                        printf("No\n%d",distance);
                        return 0;
                }
                if(m>=10){
                        m-=10;
                        distance+=60;
                }
                else if(m>=6&&t-time>1&&s-distance>17) m+=4;
                else if(m>=2&&t-time>2&&s-distance>34){
                        m+=8;
                        time++;
                }
                else if(t-time>6&&s-distance>119){
                        m+=20;
                        time+=4;
                }
                else distance+=17;
                time++;
        }
        return 0;
}
