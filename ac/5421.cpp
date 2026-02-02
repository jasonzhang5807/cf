#include <cstdio>
int n,yb[110];
int main(){
        scanf("%d",&n);
        printf("%d\n",n);
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(j!=i) yb[j]=(yb[j]+1)%2;
                        printf("%d",yb[j]);
                }
                printf("\n");
        }
        return 0;
}
