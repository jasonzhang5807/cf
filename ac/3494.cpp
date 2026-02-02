#include <cstdio>
#include <cstring>
char str[110],tgt[110];
void mov(){
        char t=str[strlen(str)-1];
        for(int i=strlen(str)-2;i>=0;i--) str[i+1]=str[i];
        str[0]=t;
}
bool equ(){
        for(int i=0;i<strlen(str);i++) if(str[i]!=tgt[i]) return false;
        return true;
}
int main(){
        freopen("b.in","r",stdin);
        freopen("b.out","w",stdout);
        scanf("%s%s",str,tgt);
        for(int i=0;i<strlen(str);i++){
                if(equ()){
                        printf("%d",i);
                        return 0;
                }
                mov();
        }
        printf("-1");
        return 0;
}
