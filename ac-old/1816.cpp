#include <set>
#include <cstdio>
using namespace std;
set<int> sz;
int main(){
        int n,x;
        char opt;
        scanf("%d",&n);
        n++;
        while(--n){
                getchar();
                opt=getchar();
                switch(opt){
                        case 'a':
                                scanf("%d",&x);
                                sz.insert(x);
                                break;
                        case 'd':
                                scanf("%d",&x);
                                sz.erase(x);
                                break;
                        case 'q':
                                printf("%d\n",*sz.begin());
                                sz.erase(sz.begin());
                                break;
                        default:
                                printf("114514\n");
                                break;
                }
        }
        return 0;
}
