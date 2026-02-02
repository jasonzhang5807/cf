#include <cstdio>
#include <set>
std::set<int> ans;
int main(){
        int a1,a2,a3,a4,a5,a6;
        scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
        for(int b=0;b<=a1;b++)
                for(int c=0;c<=a2;c++)
                        for(int d=0;d<=a3;d++)
                                for(int e=0;e<=a4;e++)
                                        for(int f=0;f<=a5;f++)
                                                for(int g=0;g<=a6;g++)
                                                        ans.insert(b+c*2+d*3+e*5+f*10+g*20);
        printf("Total=%ld",ans.size()-1);
        return 0;
}
