#include <cstdio>
#define maxn 100010
long long ans;
int a[maxn],b[maxn];
void msort(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    msort(l,mid);
    msort(mid+1,r);
    int i=l,poi=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])b[poi++]=a[i++];
        else{
            ans+=mid-i+1;
            b[poi++]=a[j++];
        }
    }
    while(i<=mid)b[poi++]=a[i++];
    while(j<=r)b[poi++]=a[j++];
    for(int k=l;k<=r;k++)a[k]=b[k];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    msort(1,n);
    printf("%lld",ans);
    return 0;
}
