#include <cstdio>
void judge(char a,char b){
        if(a=='R'&&b=='S'||a=='P'&&b=='R'||a=='S'&&b=='P')printf("Player1\n");
        else if(a==b)printf("Tie\n");
        else printf("Player2\n");
}
int main(){
        int n;
        scanf("%d",&n);
        while(n--){
                char t[20];
                char a,b;
                scanf("%s",t);
                a=t[0];
                scanf("%s",t);
                b=t[0];
                judge(a,b);
        }
        return 0;
}
