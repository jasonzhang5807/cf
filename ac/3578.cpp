#include <cstdio>
#include <cstring>
int main(){
        freopen("c.in","r",stdin);
        freopen("c.out","w",stdout);
        char a[110];
        long long n;
        int cnt=0;
        scanf("%s%lld",a,&n);
        for(int i=0;i<strlen(a);i++){
                if(a[i]=='1') cnt++;
                else break;
        }
        if(cnt>=n) printf("1");
        else printf("%c",a[cnt]);
        return 0;
}
