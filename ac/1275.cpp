#include <cstdio>
double f(double x){return x*x*x*x*x-x*x*x*x*15+x*x*x*85-x*x*225+x*274-121;}
int main(){
        double l=1.5;
        double r=2.4;
        double mid;
        for(int i=0;i<100;i++){
                mid=(l+r)/2.0;
                if(f(mid)>=0.0000005) l=mid+0.0000001;
                else if(f(mid)<=0.0000005) r=mid-0.0000001;
        }
        printf("%.6lf",mid+0.0000005);
        return 0;
}
