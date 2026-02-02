#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;
int ys, ms, ds, hs, mins;
int ye, me, de, he, mine;
int main() {
    scanf("%d-%d-%d-%d:%d", &ys, &ms, &ds, &hs, &mins);
    scanf("%d-%d-%d-%d:%d", &ye, &me, &de, &he, &mine);
    struct tm start = {0}, end = {0};
    start.tm_year = ys - 1900; start.tm_mon = ms - 1; start.tm_mday = ds;
    start.tm_hour = hs; start.tm_min = mins;
    end.tm_year = ye - 1900; end.tm_mon = me - 1; end.tm_mday = de;
    end.tm_hour = he; end.tm_min = mine;
    time_t tstart = mktime(&start), tend = mktime(&end);
    long long t=(long long)(difftime(tend, tstart) / 60);
    int n,a[5010],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++){
            if(t>=a[i]){
                    t-=a[i];
                    ans++;
            }
            else break;
    }
    printf("%d",ans);
    return 0;
}
