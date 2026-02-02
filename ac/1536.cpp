#include <stack>
#include <cstdio>
#include <stdlib.h>
std::stack<double> po;
int main(){
        double a;
        char ipt[100];
        while(1){
                for(int i=0;i<30;i++)ipt[i]='0';
                if(scanf("%s",ipt)!=1)break;
                if(ipt[0]=='+')a=po.top(),po.pop(),a+=po.top(),po.pop(),po.push(a);
                else if(ipt[0]=='-')a=-po.top(),po.pop(),a+=po.top(),po.pop(),po.push(a);
                else if(ipt[0]=='*')a=po.top(),po.pop(),a*=po.top(),po.pop(),po.push(a);
                else if(ipt[0]=='/'){
                        double b=po.top();
                        po.pop();
                        if(b==0){
                                printf("RTERR,B=0\n");
                                return 0;
                        }
                        a=po.top();
                        po.pop();
                        po.push(a/b);
                }
                else po.push(atof(ipt));
        }
        printf("%.6lf",po.top());
        return 0;
}
