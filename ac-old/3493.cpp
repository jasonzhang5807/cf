#include <cstdio>
#include <cstring>
int main(){
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
        char s[15];
        int cnt=0;
        scanf("%s",s);
        if(s[0]!='A'){
                printf("WA");
                return 0;
        }
        for(int i=2;i<=strlen(s)-2;i++) if(s[i]=='C') cnt++,s[i]='c';
        if(cnt!=1){
                printf("WA");
                return 0;
        }
        for(int i=1;i<strlen(s);i++){
                if(s[i]<'a'||s[i]>'z'){
                        printf("WA");
                        return 0;
                }
        }
        printf("AC");
        return 0;
}
