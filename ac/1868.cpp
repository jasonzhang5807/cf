#include <set>
#include <iostream>
#include <string>
using namespace std;
set<string> p;
int main(){
        int n;string ipt;
        cin>>n;
        n++;
        while(n--){
                getline(cin,ipt);
                if(p.count(ipt)){
                        cout<<"I am angry";
                        return 0;
                }
                p.insert(ipt);
        }
        cout<<"Nice hand";
        return 0;
}
