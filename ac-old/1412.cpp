#include <cstdio>
int main(){
        int n,a[110],avg=0,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
                avg+=a[i];
        }
        avg/=n;
        for(int i=0;i<n;i++){
                if(a[i]!=avg){
                        a[i+1]+=a[i]-avg;
                        ans++;
                }
        }
        printf("%d",ans);
        return 0;
}
