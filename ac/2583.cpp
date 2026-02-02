#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    if(a+b+c==d+e+f||a+b+d==c+e+f||a+b+e==c+d+f||a+b+f==c+d+e||a+c+d==b+e+f||a+c+e==b+d+f||a+c+f==b+d+e||a+d+e==b+c+f||a+d+f==b+c+e||a+e+f==b+c+d){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
